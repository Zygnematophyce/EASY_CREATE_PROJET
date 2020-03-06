#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/limits.h>
#include <string.h>

// Function to create folder in current directory.
void create_folder(char *path_folder)
{
  if (mkdir(path_folder, 0700) == -1)
    {
      printf("Failed to create %s\n", path_folder);
      exit(EXIT_FAILURE);
    }
  else
    {
      printf("Created directory : %s\n", path_folder);
      mkdir(path_folder, 0700);
    }
}

int main(int argc, char *argv[]){

  printf("Create project \n");

  // The path of the specific folder.
  char folder_path[PATH_MAX];

  // Check parameter of program.
  if (argc == 2)
    {
      // Get first parameter.
      char *base_name = argv[1];
      printf("Name folder is : %s\n", base_name);

      // Get the current directory : copie pathname of the current working
      // directory to the array pointed.
      getcwd(folder_path, sizeof(folder_path));

      // Concatenate the current directory concatenate with the new folder.
      strcat(folder_path, "/");
      strcat(folder_path, base_name);
    }
  else
    {
      // Error in parameter.
      printf("Wrong parameter e.g ./create_project exemple\n");
      exit(EXIT_FAILURE);
    }

  // Create folder.
  create_folder(folder_path);

  // In the folder create simple directory and program.
  strcat(folder_path, "/");
  strcat(folder_path, "simple_program");;
  printf("path : %s\n", folder_path);

  // Copy the path to an other source directory.
  char source_path[strlen(folder_path)];
  strcpy(source_path, folder_path);

  // Create other directory in folder_path.
  create_folder(folder_path);

  // FILE pointer for makefile.
  FILE *makefile_file;

  // Content of makefile_file.
  char makefile_containing[380] =
    "CC = gcc\nCFLAGS = -std=c11 -W -Wall\n"
    "SRC_DIR = src\n"
    "SOURCE = $(wildcard $(SRC_DIR)/*.c)\n"
    "OBJECTS = $(patsubst %, $(SRC_DIR)/%, $(notdir $(SOURCE:.c=.o)))\n"
    "TITLE = simple_program\n\n"
    "$(TITLE): $(OBJECTS)\n\t"
    "$(CC) -o $@ $^ $(CFLAGS)\n\n"
    "$(SRC_DIR)/%.o : $(SRC_DIR)/%.c\n\t"
    "$(CC) $(CFLAGS) -c $< -o $@\n\nclean :\n\t"
    "rm -rf $(SRC_DIR)/*.o\n\n"
    "cleanall :\n\t"
    "rm -rf $(SRC_DIR)/*.o $(TITLE)\n";

  // In the folder makefile_file in directory.
  strcat(folder_path, "/");
  strcat(folder_path, "Makefile");
  printf("path : %s\n", folder_path);

  makefile_file = fopen(folder_path, "w+");
  if ( makefile_file == NULL )
    {
      fprintf(stderr, "Error in allocation of file\n");
      exit(EXIT_FAILURE);
    }
  else
    {
      printf("Create a Makefile\n");
    }

  // Put the makefile script.
  fputs(makefile_containing, makefile_file);

  printf("Close Makefile\n");

  // Close makefile_file.
  fclose(makefile_file);

  // In the folder a other source folder with main.c file.
  strcat(source_path, "/");
  strcat(source_path, "src");
  printf("path : %s\n", source_path);

  // Create source path (/src).
  create_folder(source_path);

  // Copy the path of source_main to add main.c in /src folder.
  char main_source[strlen(source_path)];
  strcpy(main_source, source_path);

  // All characters of main.c file.
  char main_containing[154] =
    "#include <stdio.h>\n"
    "#include <stdlib.h>\n\n"
    "int main (void)\n"
    "{\n"
    "  // Display message\n"
    "  printf(\"Hello Jack\\n\");\n\n"
    "  // Exit program.\n "
    "  return (EXIT_SUCCESS);\n"
    "}";

  // Concatenate source_path with /main.c .
  strcat(main_source, "/");
  strcat(main_source, "main.c");
  printf("path : %s\n", main_source);

  // File pointer for main.c.
  FILE *main_file;

  // Create main.c file.
  main_file = fopen(main_source, "w+");
  if ( main_file == NULL )
    {
      fprintf(stderr, "Error in allocation of file\n");
      exit(EXIT_FAILURE);
    }
  else
    {
      printf("Create a main.c\n");
    }
  // Put the script.
  fputs(main_containing, main_file);

  printf("Close main.c\n");

  // Close the main.c file.
  fclose(main_file);

  // Exit program.
  return EXIT_SUCCESS;
}
