#include <stdio.h>
#include <stdlib.h>

#define SAMPLES_LEN 100
#define DOWNSAMPLE_K 10

void program_failure(char str[]) 
{
    perror(str);
    exit(EXIT_FAILURE);
}

int main(void) {
    printf("File IO Basics\n");

    // WRITING
    // Writing the contents of a double array into a file
    double samples[SAMPLES_LEN];
    
    for (int i = 0; i < SAMPLES_LEN; i++)
    {
        samples[i] = (i + 1) / 10.0;
        printf("%.1f,", samples[i]);
    }
    printf("\n-----\n");

    // write samples array to a file (in binary mode)
    FILE *fp = fopen("samples.bin", "wb");
    if (!fp)
    {
        program_failure("File could not be created.");
    }
    
    size_t written_count = fwrite(samples, sizeof(samples[0]), SAMPLES_LEN, fp);

    if (written_count != SAMPLES_LEN)
    {
        program_failure("File writing failed.");
    }

    fclose(fp);

    // READING
    // Read the content of the (binary) file
    // Read downsampled samples from the file (sub-samples of 10 items)
    // (indexes 9, 19, ... 99)
    double sample_k[SAMPLES_LEN / DOWNSAMPLE_K];

    // open the previously saved file
    fp = fopen("samples.bin", "rb");

    // SAMPLES_LEN / DOWNSAMPLE_K = 100 / 10 = 10
    for (int i = 0; i < SAMPLES_LEN / DOWNSAMPLE_K; i++)
    {
        // shifting 9 * sizeof(one_double_element)
        int offset = (DOWNSAMPLE_K - 1) * sizeof(sample_k[0]);
        if (fseek(fp, offset, SEEK_CUR) != 0) 
        {
            program_failure("feek failed.");
        }   
        size_t count = fread(&sample_k[i], sizeof(sample_k[0]), 1, fp);
        if (count != 1)
        {
            if (feof(fp))
            {
                program_failure("Unexpected End of File.");
            }
            else 
            {
                program_failure("Error readin the file.");
            }
        }
        printf("%.1f, ", sample_k[i]);
    }

    return 0;
}
