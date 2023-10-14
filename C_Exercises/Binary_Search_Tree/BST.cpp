#include "tree.h"
// Included tree library.

int main()
{
    // Created Binary Tree pointer and assigned null.
    BinaryTree *binaryTree = NULL;

    // Created required variables for: operation choosing, user input, sum, average and index counters.
    int sum = 0, choice, number, j, avg, f;

    // Created an infinite loop for ending program when user decides to.
    while (true)
    {
        // Printed the selectable options to console for user.
        printf("1: Add\n2: Search Element\n3: Arithmetic Mean of Leaves\n4: Find Greater Elements Than A Number\n5: Find Elements At Level\n6: Exit\n");
        // Read the user input and assigned to 'choice' variable.
        scanf("%d", &choice);

        // Created a switch statement for executing separated functions by user choice.
        switch (choice)
        {
            // If user chooses 1:
        case 1:
            // Guided user to adding an element to binary tree.
            printf("Enter the number that you want to add...\n");
            // Read the user input and assigned to 'number' variable.
            scanf("%d", &number);
            // Called the add function for Binary Tree with 'number' and tree pointer.
            binaryTree = Add(binaryTree, number);
            // Cleared console.
            ClearConsole();
            break;

            // If user chooses 2:
        case 2:
            // Assigned 1 to 'stepCount' variable for starting from 1.
            stepCount = 1;
            // Guided user to search an element in binary tree.
            printf("Enter the number that you want to search...\n");
            // Read the user input and assigned to 'number' variable.
            scanf("%d", &number);
            // Called the search function
            Search(binaryTree, number);
            // Waited for user and cleared console.
            WaitForUser();
            ClearConsole();
            break;

            // If user chooses 3:
        case 3:
            // Assigned 0 to index counters and sum
            i = 0;
            j = 0;
            sum = 0;
            // Called function for calculating arithmetic mean of leaves.
            Leaf(binaryTree);

            // If function did not increased 'i', that means tree is empty
            if (i == 0)
            {
                // User informed about empty tree and waited for user
                printf("Tree is empty! Add new numbers by choosing option 1.\n");
                WaitForUser();
                ClearConsole();
                break;
            }

            // If tree is not empty calculated sum of leaves and divided by leaf count for calculating arithmetic mean
            while (j < i)
            {
                sum = sum + leaves[j];
                j++;
            }

            // Calculated arithmetic mean by dividing sum to leaf count.
            avg = sum / j;
            // Printed arithmetic mean to console.
            printf("Arithmetic mean of leaves : %d\n", avg);
            // Waited for user and cleared console.
            WaitForUser();
            ClearConsole();
            break;

            // If user chooses 4:
        case 4:
            // Guided user to enter a number for finding greater elements in tree.
            printf("Enter the number you want to find elements that are greater than the number...\n");
            // Read the user input and assigned to 'number' variable.
            scanf("%d", &number);
            // Printed all elements thats greater than number to console.
            printf("The elements thats greater than %d : ", number);
            // Assigned 0 to control and index variables for reset.
            control = 0;
            index = 0;
            // Called FindBigElements function.
            FindBigElements(binaryTree, number);

            // If control is 0 there is no greater element in tree prints 'None', else prints elements to console.
            if (control == 0)
                printf("None.\n");
            else
            {
                for (int i = 0; i < index; i++)
                {
                    // If the element is last element, printed element and added new line char('\n') to end.
                    if (i == index - 1)
                        printf("%d\n", bigElementsArray[i]);
                    else // Else printed element with '-' separator.
                        printf("%d - ", bigElementsArray[i]);
                }
            }
            // Waited for user and cleared console.
            WaitForUser();
            ClearConsole();
            break;

        // If user chooses 5:
        case 5:
            // Guided user to enter a number for finding greater elements in tree.
            printf("Which level of tree elements do you want to see...\n");
            // Read the user input and assigned to 'number' variable.
            scanf("%d", &number);

            // Assigned 0 to f and index variables for reset.
            f = 0;
            index = 0;

            // Printed all elements of level to console.
            printf("Elements of level %d. : ", number);
            // Called level function.
            Level(binaryTree, number);

            // If there is no element on specified level
            if (index == 0)
                printf("None!");

            // If there is elements in specified level printed to console.
            for (int i = 0; i < index; i++)
            {
                // If the element is last element, printed element and added new line char('\n') to end.
                if (i == index - 1)
                    printf("%d\n", levelArray[i]);
                else // Else printed element with '-' separator.
                    printf("%d - ", levelArray[i]);
            }
            // Waited for user and cleared console.
            WaitForUser();
            ClearConsole();
            break;

        // If user chooses 6:
        case 6:
            // Stopped program with exit code 0.
            return 0;
            break;

        // If user input is invalid, cleared console and re-printed options.
        default:
            ClearConsole();
            break;
        }
    }

    // Stopped program with exit code 0.
    return 0;
}
