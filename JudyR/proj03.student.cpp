#include <string>
#include <iostream>

enum Operation
{
 NONE,
 APPEND,
 TRUNCATE,
 ERROR
};

const char* OperationStr[] = { "NONE", "APPEND", "TRUNCATE", "ERROR" };

const char* getOperationStr(Operation o)
{
    return OperationStr[o];
}

/**
 * This function consumes the comnand line arguments through argc, and argv
 * and produces a operation (append, truncate, none) along with source and 
 * destination file paths. The uin32_t parameter is the buffer size for read
 * and writes to the source and destination files. 
 */
Operation GetOptions(int argc, char *argv[], uint32_t& buffer,
                     std::string& SourceFilePath, std::string& DestinationFilePath)
{
    buffer = 64;
    Operation operation = NONE;
    
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            switch(argv[i][1])
            {
                case 'a':
                {
                    if (NONE == operation)
                        operation = APPEND;
                    else
                    {
                        std::cout << " operation (truncate, or append) already specified";
                        return ERROR;
                    }
                    break;
                }
                            
                case 't':
                {
                    if (NONE == operation)
                        operation = TRUNCATE;
                    else
                    {
                        std::cout << " operation (truncate, or append) already specified";
                        return ERROR;
                    }
                    break;
                }
                    
                case 'b':
                {
                    buffer = atoi(argv[++i]);
                    break;
                }
            }
        }
        else
        {
            if (SourceFilePath.empty())
                SourceFilePath = argv[i];
            else if (DestinationFilePath.empty())
                DestinationFilePath = argv[i];
            else
            {
                std::cout << "Error in command line argument: " << argv[i]
                          << " not valid , file paths already specified" << std::endl;
                return ERROR;    
            }
        }
    }
    return operation;
}


int main(int argc, char *argv[])
{
    int retCode = 0;

    std::string srcfile, dstfile;
    uint32_t buffer;
    Operation operation = GetOptions(argc, argv, buffer, srcfile, dstfile);

    std::cout << " Opeation: " << getOperationStr(operation)
              << " buffer: " << buffer
              << " source file: " << srcfile
              << " destiation file: " << dstfile << std::endl;

    return retCode;
}
