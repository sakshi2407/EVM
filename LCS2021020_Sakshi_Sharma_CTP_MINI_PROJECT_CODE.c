

/*                                              ELECTRONIC VOTING MACHINE                                                        */

#include <stdio.h>  // Header files
#include <string.h>
#include <stdlib.h>
#define max_voter 1000
int bin_search(int a[], int key, int n)
{       // function to implement the binary search technique
    int low = 0, mid, high = n - 1;
    while (low <= high)
    {   
        mid = (low + high) / 2;
        if (key == a[mid])
            return 0;   // if value is found, it returns 0
        else if (key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 1;           // if value is not present, it returns 1
}

int count(int n)
{       // function to count the number of digits in n
    int c = 0;
    while (n > 0)
    {
        c++;
        n /= 10;
    }
    return c;
}

int vote(int size, int voter[])
{       // funtion for implementing the voter's tasks
    int voter_id;
    for (int i = 0; i < 55; i++)
        printf(" ");
    printf("Enter your voter id : ");
    scanf("%d", &voter_id);     
    if (count(voter_id) != 8)
    {   // checking the number of digits of voter id entered by the voter
        // invoking function count(int)
        // if count is not 8, voter id is invalid
        for (int i = 0; i < 55; i++)
            printf(" ");
        printf("Invalid voter ID!\n");
        for (int i = 0; i < 55; i++)
            printf(" ");
        printf("Please enter a valid voter ID\n\n");
        getch();
        return vote(size, voter);   // using recursion
                                    // simply running the function again, accepting the voter id until the voter inputs a 
                                    // valid voter id
    }
    if (bin_search(voter, voter_id, size) == 1)
    {   // invoking bin_search function to check whether voter id entered is already present in the voter array or not
        // here we have made sure that the scenario of bogus voting is avoided
        // if voter id is unique, it is added in the array and 1 is returned to the main() function
        int i = size - 1;
        while (voter_id < voter[i] && i >= 0)
        {
            voter[i + 1] = voter[i];
            i--;
        }
        voter[i + 1] = voter_id;
        return 1;
    }
    else
    {   // if voter id is already present in the array, 0 is returned to the main() function
        return 0;
    }
}

int admin()
{          // function for implementing the admin's tasks
    char sys_password[30] = "project";      // default admin password is "project"
    char password[30];      // for storing the entered password
    for (int i = 0; i < 55; i++)
        printf(" ");
    printf("Enter your password : ");
    scanf("%s", password);
    if (strcmp(password, sys_password) == 0)
    {   // strcmp() to compare 2 strings
        // here it is used to check whether the entered password matches the admin password
        // if the value of strcmp function is 0, password entered is correct
        // here we have ensured that only admin can access his/her screen, thereby restricting others from accessing it
        printf("\n\n");
        for (int i = 0; i < 55; i++)
            printf(" ");
        printf("Authorization successful\n");
        for (int i = 0; i < 55; i++)
            printf(" ");
        printf("Press enter to proceed\n");
        getch();
        system("cls");
        printf("\n\n\n");
        for (int i = 0; i < 79; i++)
            printf(" ");
        printf("Admin\n");
        for (int i = 0; i < 79; i++)
            printf(" ");
        for (int i = 0; i < 5; i++)
            printf("*");
        printf("\n\n\n");
        for (int i = 0; i < 35; i++)
            printf(" ");
        for (int i = 0; i < 101; i++)
            printf("_");
        for (int i = 0; i < 35; i++)
            printf(" ");
        printf("\n\n\n");
        for (int i = 0; i < 55; i++)
            printf(" ");
        // Menu driven, giving choice to the admin
        printf("Press 1 to terminate the poll\n");
        for (int i = 0; i < 55; i++)
            printf(" ");
        printf("Press 2 to return back to voting screen\n\n");
        while (1)
        {
            int sys_choice;
            for (int i = 0; i < 55; i++)
                printf(" ");
            printf("Enter your choice : ");
            scanf("%d", &sys_choice);
            // storing admin's choice in sys_choice
            if (sys_choice == 1)
            {   // if admin presses 1, control flows to the results screen to display the results
                printf("\n\n\n");
                for (int i = 0; i < 55; i++)
                    printf(" ");
                printf("Press enter to terminate the poll and display the results\n\n\n");
                for (int i = 0; i < 35; i++)
                    printf(" ");
                for (int i = 0; i < 101; i++)
                    printf("_");
                for (int i = 0; i < 35; i++)
                    printf(" ");
                getch();
                system("cls");
                return 1;
                // function returns 1 to the main() function signalling it to go to the results screen
            }
            else if (sys_choice == 2)
            {   // if admin presses 2, control is redirected to the menu driven screen to resume voting
                printf("\n\n\n");
                for (int i = 0; i < 55; i++)
                    printf(" ");
                printf("Press enter to resume voting\n\n\n");
                for (int i = 0; i < 35; i++)
                    printf(" ");
                for (int i = 0; i < 101; i++)
                    printf("_");
                for (int i = 0; i < 35; i++)
                    printf(" ");
                getch();
                return 0;
                // function returns 0 to the main() function signalling it to go the menu driven screen
            }
            else
            {   // if admin enters an invalid choice,
                // admin is again asked to enter his/her choice
                printf("\n");
                for (int i = 0; i < 55; i++)
                    printf(" ");
                printf("Invalid choice!!!\n\n");
            }
        }
    }
    else
    {   // if password entered is not correct, corresponding message is displayed.
        // control flows to the menu driven screen
        printf("\n\n");
        for (int i = 0; i < 55; i++)
            printf(" ");
        printf("Wrong Password!!");
        getch();
        system("cls");
    }
}

int main()
{       // main() function 
    system("COLOR 09"); // changing the text and background color (light blue text on black background)
    // 9 --> light blue
    // 0 --> black 
    system("cls");  // used for clearing the screen
    getch();    // used for entering a single character 
                // we have generally used it for detecting when user presses enter
    // Welcome screen display starts
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 171; j++)
            printf("*");
        printf("\n");
    }
    for (int i = 0; i < 61; i++)
        printf("*");
    printf("  _______    \t\t\t      ");
    for (int i = 0; i < 69; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < 61; i++)
        printf("*");
    printf("  |            \\          /  |\\      /|  ");
    for (int i = 0; i < 69; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < 61; i++)
        printf("*");
    printf("  |             \\        /   | \\    / |  ");
    for (int i = 0; i < 69; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < 61; i++)
        printf("*");
    printf("  |_______       \\      /    |  \\  /  |  ");
    for (int i = 0; i < 69; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < 61; i++)
        printf("*");
    printf("  |               \\    /     |   \\/   |  ");
    for (int i = 0; i < 69; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < 61; i++)
        printf("*");
    printf("  |                \\  /      |        |  ");
    for (int i = 0; i < 69; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < 61; i++)
        printf("*");
    printf("  |_______          \\/       |        |  ");
    for (int i = 0; i < 69; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < 61; i++)
        printf("*");
    printf("  ______________________________________\a ");
    for (int i = 0; i < 69; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 171; j++)
            printf("*");
        if (i != 20)
            printf("\n");
    }
    // Welcome screen display ends here 
    getch();
    system("cls");
    int noc;
    // Candidate screen display starts
    printf("\n\n\n");
    for (int i = 0; i < 75; i++)
        printf(" ");
    printf("Candidate Details\n");
    for (int i = 0; i < 75; i++)
        printf(" ");
    for (int i = 0; i < 17; i++)
        printf("*");
    printf("\n\n\n");
    for (int i = 0; i < 35; i++)
        printf(" ");
    for (int i = 0; i < 101; i++)
        printf("_");
    for (int i = 0; i < 35; i++)
        printf(" ");
    printf("\n\n\n");
    for (int i = 0; i < 55; i++)
        printf(" ");
    printf("Enter number of candidates : ");
    scanf("%d", &noc);  // taking the input for the number of candidates and storing it in noc
    int voter[100];
    char cname[100][30], symbol[100];
    int votes[100];
    for (int k = 0; k < 100; k++)
    {   // initilializing all the elements of voter and votes array to 0
        votes[k] = 0;
        voter[k] = 0;
    }
    char temp; // for storing the symbol of a candidate
    int i = 0;
    printf("\n");
    while (i < noc)
    {
        printf("\n");
        for (int i = 0; i < 35; i++)
            printf(" ");
        for (int i = 0; i < 35; i++)
            printf("-");
        printf(" Enter details of candidate %d ", i + 1);
        for (int i = 0; i < 35; i++)
            printf("-");
        for (int i = 0; i < 35; i++)
            printf(" ");
        printf("\n\n");
        for (int i = 0; i < 55; i++)
            printf(" ");
        printf("Enter name of the candidate   : ");
        scanf("%s", cname[i]);  // storing name of the candidate
        for (int i = 0; i < 55; i++)
            printf(" ");
        printf("Enter symbol of the candidate : ");
        scanf(" %c", &temp);    // storing the symbol of the candidate in a temporary variable
        int flag = 0;
        for (int j = 0; j < i; j++)
        {   // applying linear search technique
            // iterating through the array and checking whether temp is already present in the symbol[] array or not
            // here we have ensured that no two candidates have the same symbol
            if (temp == symbol[j])
            {
                flag = 1;   // set flag to 1 if symbol entered is already present and break the loop
                break;
            }
        }
        if (flag == 1)
        {   // if duplicate symbol is found
            // we ask the user to enter some other symbol
            for (int i = 0; i < 55; i++)
                printf(" ");
            printf("The symbol has already been taken!! Please use different symbol.\n\n");
        }
        else
        {   // if symbol entered is unique, 
            // stores the symbol in the array symbol[]
            symbol[i] = temp;
            i++;
        }
    }
    printf("\n\n\n");
    for (int i = 0; i < 57; i++)
        printf(" ");
    printf("The details of all the candidates have been stored\n\n\n");
    for (int i = 0; i < 34; i++)
        printf(" ");
    for (int i = 0; i < 102; i++)
        printf("_");
    for (int i = 0; i < 35; i++)
        printf(" ");
    // Candidate screen display ends here
    getch();
    system("cls");
    voter[0] = 0;
    int choice, size = 0;
    // size is for storing the current size of the voter array
    while (1)
    {
        if (size == max_voter)
        {   // if size of the voter array becomes equal to the maximum voters, voting terminates and execution is directed to the results screen
            // results are displayed on the screen
            printf("\n\n\n");
            for (int i = 0; i < 79; i++)
                printf(" ");
            printf("RESULTS\n");
            for (int i = 0; i < 79; i++)
                printf(" ");
            for (int i = 0; i < 7; i++)
                printf("*");
            printf("\n\n");
            for (int i = 0; i < 67; i++)
                printf(" ");
            printf("Symbol\t\tVotes\t\tName\n\n");
            for (int i = 0; i < noc; i++)
            {
                for (int i = 0; i < 55; i++)
                    printf(" ");
                printf("%c\t\t%d\t\t%s\n", symbol[i], votes[i], cname[i]);
            }
            getch();
            break;  // breaking the loop after results are displayed 
        }
        // Menu Driven screen display
        printf("\n\n\n\n\n\n");
        for (int i = 0; i < 55; i++)
            printf(" ");
        printf("Press 1 if you are a voter\n");
        for (int i = 0; i < 55; i++)
            printf(" ");
        printf("Press 2 if you are an admin\n\n");
        for (int i = 0; i < 55; i++)
            printf(" ");
        printf("Enter your choice : ");
        scanf("%d", &choice);   // storing the user's choice in choice
        printf("\n\n\n");
        if (choice == 1)
        {   // if choice is 1, invoke vote() function
            if (vote(size, voter) == 0)
            {   // if vote function returns 0, it means a voter has already voted 
                // displaying the corresponding message and going back to the Menu Driven screen
                for (int i = 0; i < 55; i++)
                    printf(" ");
                printf("You have already voted!!\n");
                getch();
                system("cls");
            }
            else
            {   // if voter id is unique, proceed to the "cast your vote" screen
                size++;
                system("cls");
                // Cast your vote screen display starts
                printf("\n\n\n");
                for (int i = 0; i < 77; i++)
                    printf(" ");
                printf("Cast your Vote\n");
                for (int i = 0; i < 77; i++)
                    printf(" ");
                for (int i = 0; i < 14; i++)
                    printf("*");
                printf("\n\n\n");
                for (int i = 0; i < 35; i++)
                    printf(" ");
                for (int i = 0; i < 101; i++)
                    printf("_");
                for (int i = 0; i < 35; i++)
                    printf(" ");
                printf("\n\n\n");
                for (int i = 0; i < 55; i++)
                    printf(" ");
                printf("Welcome!!\n\n");
                for (int i = 0; i < 55; i++)
                    printf(" ");
                printf("Press enter to show the details of all the candidates ");
                getch();
                printf("\n\n\n");
                for (int i = 0; i < 79; i++)
                    printf(" ");
                printf("Candidates\n");
                for (int i = 0; i < 79; i++)
                    printf(" ");
                printf("**********\n");
                for (int i = 0; i < 72; i++)
                    printf(" ");
                for (int i = 0; i < 21; i++)
                    printf("_");
                printf("\n\n");
                for (int i = 0; i < 74; i++)
                    printf(" ");
                printf("Symbol\tName\n");
                for (int i = 0; i < noc; i++)
                {
                    for (int i = 0; i < 74; i++)
                        printf(" ");
                    printf("%c\t\t%s\n", symbol[i], cname[i]);
                }   // showing details of all the candidates along with their symbols
                for (int i = 0; i < 72; i++)
                    printf(" ");
                for (int i = 0; i < 21; i++)
                    printf("_");
                printf("\n");
                char sym;
                int flag = 0;   // initializing flag to 0 
                while (flag != 1)
                {
                    printf("\n");
                    for (int i = 0; i < 55; i++)
                        printf(" ");
                    printf("Enter the symbol of your Representative : ");
                    scanf(" %c", &sym); // storing the symbol of the voter's representative in sym
                    for (int i = 0; i < noc; i++)
                    {   // searching for the symbol entered in symbol array 
                        if (sym == symbol[i])
                        {
                            flag = 1;       // setting flag to 1
                            votes[i]++;     // incrementing the number of votes at that particular index at which sym is found
                            printf("\n");
                            for (int i = 0; i < 55; i++)
                                printf(" ");
                            printf("Congratulations!!! Your vote has been cast.\n\n");
                            for (int i = 0; i < 55; i++)
                                printf(" ");
                            printf("Press any key to continue\n\n\n");
                            for (int i = 0; i < 34; i++)
                                printf(" ");
                            for (int i = 0; i < 102; i++)
                                printf("_");
                            for (int i = 0; i < 35; i++)
                                printf(" ");
                            // Cast your vote screen display ends here
                            getch();
                            system("cls");
                            break;  // breaking the loop after vote has been cast
                        }
                    }
                    if (flag == 0)
                    {   // if flag is 0 i.e. voter enters an invalid symbol
                        // printing the corresponding message and asking the voter to re-enter the symbol
                        for (int i = 0; i < 55; i++)
                            printf(" ");
                        printf("Invalid Symbol!!\n\n");
                        for (int i = 0; i < 55; i++)
                            printf(" ");
                        printf("Press enter to continue\n\n");
                        getch();
                    }
                }
            }
        }
        else if (choice == 2)
        {   // if choice is 2, invoke the admin() function
            if (admin() == 1)
            {   // if admin() function returns 1, it signals the main() function to go to the results screen
                // Results screen display starts here
                printf("\n\n\n");
                for (int i = 0; i < 79; i++)
                    printf(" ");
                printf("RESULTS\n");
                for (int i = 0; i < 79; i++)
                    printf(" ");
                for (int i = 0; i < 7; i++)
                    printf("*");
                printf("\n\n");
                for (int i = 0; i < 34; i++)
                    printf(" ");
                for (int i = 0; i < 102; i++)
                    printf("_");
                for (int i = 0; i < 35; i++)
                    printf(" ");
                printf("\n\n");
                for (int i = 0; i < 67; i++)
                    printf(" ");
                printf("Symbol\tVotes\t\tName\n\n");
                for (int i = 0; i < noc; i++)
                {
                    for (int i = 0; i < 67; i++)
                        printf(" ");
                    printf("%c\t\t%d\t\t%s\n", symbol[i], votes[i], cname[i]);
                }   // Displaying the results of voting
                printf("\n\n");
                for (int i = 0; i < 34; i++)
                    printf(" ");
                for (int i = 0; i < 102; i++)
                    printf("_");
                for (int i = 0; i < 35; i++)
                    printf(" ");
                // Results screen display ends here
                getch();
                break;  // breaks the infinite while loop
                        // execution goes to the Credits screen
            }
            else
            {   // if admin() doesn't return 1, it signals the main() function to resume voting 
                // Control flows back to the menu driven screen
                system("cls");
            }
        }
        else
        {   // if choice entered is invalid,
            // printing corresponding message and going back to menu driven screen
            for (int i = 0; i < 55; i++)
                printf(" ");
            printf("Invalid choice!!");
            getch();
            system("cls");
        }
    }
    system("cls");
    // Credits screen display starts here
    printf("\n\n\n\n\n");
    for (int i = 0; i < 77; i++)
        printf(" ");
    printf("Credits\n");
    for (int i = 0; i < 77; i++)
        printf(" ");
    for (int i = 0; i < 7; i++)
        printf("*");
    getch();
    printf("\n\n");
    for (int i = 0; i < 77; i++)
        printf(" ");
    printf("Sakshi Sharma\n");
    getch();
    for (int i = 0; i < 77; i++)
        printf(" ");
    printf("Abhishek Goenka\n");
    getch();
    for (int i = 0; i < 77; i++)
        printf(" ");
    printf("Shraddha Gulati\n");
    getch();
    for (int i = 0; i < 77; i++)
        printf(" ");
    printf("Sahil Kumar\n\n");
    getch();
    for (int i = 0; i < 77; i++)
        printf(" ");
    printf("SIGNING OFF :)\n");
    getch();
    // Credits screen display ends here
    system("cls");
}
