//
//  cal_diets.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while (fscanf(file, "%s %d", diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake) != EOF) 
	{
    	diet_list_size++;
        if (diet_list_size >= MAX_DIETS){
        	break;
		}
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    for (i=0; i<diet_list_size; i++){
    	printf("%s - %d kcal\n", diet_list[i].food_name, diet_list[i].calories_intake);		//diets.txt list
	}
    
	// ToCode: to enter the diet to be chosen with exit option
    printf("0. END\n");			//choose 0 -> end
    printf("Enter the diet: ");
    scanf("%s", &choice);		//scan choice
    
    if (choice == 0){
    	printf("END\n");
    	return;
	}		//0 -> END
	

    // ToCode: to enter the selected diet in the health data
    

    // ToCode: to enter the total calories intake in the health data
	for (int i=0; i<diet_list_size; i++) {
        if (strcmp(choice, diet_list[i].food_name) == 0) {		//choice = diet(list)
            health_data -> diet[health_data->diet_count] = diet_list[i];
            health_data -> diet_count++;
            health_data -> total_calories_intake += diet_list[i].calories_intake;
            printf("%s - %d kcal \n", diet_list[i].food_name, diet_list[i].calories_intake);
            return;
        }
    }
	printf("Please try again. Enter the diet name from the list");		//invalid diet(list X)
}

