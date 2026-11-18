#include <stdio.h>
#include <stdlib.h>

/**
 * Rnu and debug to observe the memory leak take effect
 */

struct Request
{
    char *body;
    size_t body_size;
};

struct Request *receive_request() 
{
    struct Request *request = malloc(sizeof *request);

    if (request == NULL)
    {
        printf("Req allocation failed\n");
        return NULL;;
    }

    request->body_size = 4096;
    request->body = malloc(request->body_size);

    if (request->body == NULL)
    {
        printf("Req body allocation failed\n");
        free(request);
        return NULL;
    }
    return request;
}

void destroy_request_leaky(struct Request *request)
{
    /*
     * BUG:
     * request->body was separately allocated,
     * but we never free it.
     * Solution is to free(request->body) first and then free(request)
     */
    free(request);
}

int main()
{
    for (int i = 0; i < 1000; i++)
    {
        struct Request *request = receive_request();

        if (request == NULL)
        {
            printf("Allocation failed.\n");
            return 1;
        }

        request->body[0] = 'A';

        destroy_request_leaky(request);
    }
    printf("Memory Leak Example\n");

    return 0;
}