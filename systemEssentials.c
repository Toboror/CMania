//
// Created by tobia on 07.08.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "systemEssentials.h"
#include "cJSON/cJSON.h"
#include <stdbool.h>

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

    bool foundUpdate = false;

    CURL *curl;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.github.com/repos/Toboror/CMania/commits");

        // GitHub requires a user-agent
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "my-c-client");

        // Write callback
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            cJSON *json = cJSON_Parse(chunk.memory);
            if (json) {
                const cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(json, "updated_at");
                if (cJSON_IsString(updated_at) && updated_at->valuestring != NULL) {
                    foundUpdate = true;
                    printf("Repo last updated at: %s\n", updated_at->valuestring);
                }
                cJSON_Delete(json);
            } else {
                printf("Failed to parse JSON.\n");
            }
        }

        curl_easy_cleanup(curl);
    }

    free(chunk.memory);
    curl_global_cleanup();

    printf("Checking for updates...\n");
    if (foundUpdate) {
        printf("Found update! Updating now.");
    } else {
        printf("Did not find update. Continuing.");
    }
}