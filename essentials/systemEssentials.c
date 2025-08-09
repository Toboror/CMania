//
// Created by tobia on 07.08.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "../systemEssentials.h"
#include "../cJSON/cJSON.h"
#include <stdbool.h>
#ifdef _WIN32
#include <windows.h>
#define SLEEP(x) Sleep((x)*1000)
#else
#endif


struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if(mem->memory == NULL) {
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

void check_for_updates() {

    CURL *curl;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.github.com/repos/Toboror/CMania/commits");
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "my-c-client");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            cJSON *json = cJSON_Parse(chunk.memory);
            if (json && cJSON_IsArray(json)) {
                cJSON *latest_commit = cJSON_GetArrayItem(json, 0);
                if (latest_commit) {
                    cJSON *sha = cJSON_GetObjectItemCaseSensitive(latest_commit, "sha");
                    cJSON *commit_obj = cJSON_GetObjectItemCaseSensitive(latest_commit, "commit");
                    cJSON *author = cJSON_GetObjectItemCaseSensitive(commit_obj, "author");
                    cJSON *date = cJSON_GetObjectItemCaseSensitive(author, "date");

                    if (cJSON_IsString(sha) && sha->valuestring && cJSON_IsString(date) && date->valuestring) {
                        printf("Newest update date: %s\n", date->valuestring);

                        // Read last saved SHA
                        char last_sha[100] = {0};
                        FILE *fp = fopen("last_sha.txt", "r");
                        if (fp) {
                            fgets(last_sha, sizeof(last_sha), fp);
                            fclose(fp);
                        }

                        // Compare SHA
                        if (strcmp(last_sha, sha->valuestring) != 0) {
                            printf("New update found!\n");
                            system("git pull");
                            printf("Successfully updated!");

                            // Save new SHA
                            FILE *fp2 = fopen("last_sha.txt", "w");
                            if (fp2) {
                                fprintf(fp2, "%s", sha->valuestring);
                                fclose(fp2);
                            }
                        } else {
                            printf("No new updates found.\n");
                        }
                    }
                }
                cJSON_Delete(json);
            } else {
                printf("Failed to parse JSON or unexpected format.\n");
            }
        }

        curl_easy_cleanup(curl);
    }

    free(chunk.memory);
    curl_global_cleanup();

}
