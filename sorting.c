#include <stdio.h> /* libraries that will be used */
#include <stdlib.h>
#include <string.h>
/* General info: in this program we did create structs for each data type. when user enters a data to order any data type,
it has been linked to related arrayç Then we call the related function which orders the data types (all data types have different
functions) */
typedef struct Movie{ /* struct that holds the infos of the movies MAIN STRUCT */
	double budget;
	int genre;
	char* name;
	double score;
	int year;
}movie;
typedef struct budget_s{ /* struct that holds the budget informations of the whole movies we will order the movies by budget
with using this struct*/
	double budget;
	int index;
	int order;
}budget_s;
typedef struct year_s{
	/* struct that holds the year informations of the whole movies we will order the movies by year
with using this struct*/
	int year;
	int index;
	int order;
}year_s;
typedef struct name_s{
	/* struct that holds the name informations of the whole movies we will order the movies by name
with using this struct*/
	char* name;
	int index;
	int order;
}name_s;
typedef struct score_s{
		/* struct that holds the score informations of the whole movies we will order the movies by score
with using this struct*/
	double score;
	int index;
	int order;
}score_s;
typedef struct genre_s{
/* struct that holds the genre informations of the whole movies we will order the movies by genre
with using this struct*/
	int genre;
	int index;
	int order;
}genre_s;
typedef struct string{ /* structure which help us implementing orderString function */
	char str[40];
}string;

void asc_sort(int a,year_s *Year){ /* function takes the year_s structs as an input and orders them in ascending order */
year_s temp; /* temporary year_s struct for swapping */
 int i, j;
 for(i=0;i< a-1;i++)
 {
  for(j=i+1;j< a;j++)
  {
   if(Year[i].year>Year[j].year) /* if the year now is bigger than next year, make next year previous */ 
   {
    temp = Year[i];
    Year[i]= Year[j];
    Year[j] = temp;
   }
  }
 }
}
void asc_sort1(int a,budget_s* Budget){/* function takes the budget_s structs as an input and orders them in ascending order */
 /* temporary budget_s struct for swapping */
budget_s temp;
 int i, j;
 for(i=0;i< a-1;i++)
 {
  for(j=i+1;j< a;j++)
  {
   if(Budget[i].budget>Budget[j].budget)
   {
    temp = Budget[i];	 /* if the budget now is bigger than next movies', make next movie's budget previous */ 
    Budget[i]= Budget[j];
    Budget[j] = temp;
   }
  }
 }
}
void asc_sort2(int a,score_s *Score)  {/* function takes the score_s structs as an input and orders them in ascending order */
 /* temporary score_s struct for swapping */
score_s temp;
 int i, j;
 for(i=0;i< a-1;i++)
 {
  for(j=i+1;j< a;j++)
  {
   if(Score[i].score>Score[j].score)/* if the score now is bigger than next movies', make next movie's score previous */ 
   {
    temp = Score[i];
    Score[i]= Score[j];
    Score[j] = temp;
   }
  }
 }
}
void asc_sort3(int a,genre_s* Genre) {/* function takes the genre_s structs as an input and orders them in ascending order */
 /* temporary genre_s struct for swapping */
genre_s temp;
 int i, j;
 for(i=0;i< a-1;i++)
 {
  for(j=i+1;j< a;j++)
  {
   if(Genre[i].genre>Genre[j].genre)/* if the genre now is bigger than next movies', make next movie's genre previous */
   {
    temp = Genre[i];
    Genre[i]= Genre[j];
    Genre[j] = temp;
   }
  }
 }
}
void orderStrings(int a,name_s* Name) {/*this function takes a name_s structure pointer which holds strings in it and then
make them in alphabetical order */ 
	int i,j;
	char* temp= (char*) malloc(25*sizeof(char));
	for(i=0;i<=a;i++)
      for(j=i+1;j<=a;j++){
         if(strcmp(Name[i].name,Name[j].name)>0){ /* using strcmp to understand which one is in the alphabetical order */
            strcpy(temp,Name[i].name);
            strcpy(Name[i].name,Name[j].name);
            strcpy(Name[j].name,temp);
         }
         free(temp);
      }
}
void orderStrings_1(int a,movie* array,int index_s,int index_e){
	/*this function orders the movies in alphabetical order in the given interval 
	index_s and index_e are the intervals of the movies that will be ordered*/ 
	int i,j,p=0;
	char* temp= (char*) malloc(25*sizeof(char));
	string* str_s= (string*) malloc(a*sizeof(string)); /*allocating a string pointer array for the movies in the given interval*/
	for(i=index_s;i<=index_e;i++){
		strcpy(str_s[p].str,array[i].name); /* assingning their's names in that structure */
		p++;
	}	
	for(i=0;i<=a;i++){
      for(j=i+1;j<=a;j++){
         if(strcmp(str_s[i].str,str_s[j].str)>0){ /* using strcmp to understand which one is in the alphabetical order */
            strcpy(temp,str_s[i].str); /* using swapping method to change the order.since we are using strings we have to use
			stcpy*/
            strcpy(str_s[i].str,str_s[j].str);
            strcpy(str_s[j].str,temp);	
         }
      }
  	}
      p=0;
      	for(i=index_s;i<=index_e;i++){ /* after we order the strings, we are updating the movies names' */
      		strcpy(array[i].name,str_s[p].str);
      		p++;
		  }
	  free(temp);
}
void removeSpaces(char* temp) {
    const char* str = temp; /* function removes the spaces of given string */
    do {
        while (*str == ' ') { /* until see the blank, increment the index */
            ++str;
        }
    } while (*temp++ = *str++);
}
/* this function orders the budgets in ascending order */
int  orderBudget(movie* array,double start_budget,double end_budget,int l,budget_s* Budget,char sample [20][20]){
	int i,a=0,k;
	double tempy;
	int var;
	int temp;
	for(i=0;i<l;i++){ 
	tempy= array[i].budget;
		if((start_budget<=tempy) && (tempy<=end_budget)){ /* we are searching for the movies with budget that between the 
		user inputs */
				Budget[a].budget=array[i].budget;
				Budget[a].index=i; /* when we find them, we have to save their index(we are they in the movie order) in related
				struct */
				Budget[a].order=i;
				a++; /* counts the movies which are in the interval */
		}
	}
	asc_sort1(a,Budget); /* after we determine the movies, we are sorting them in ascending order ac.to budget */
	for(i=0;i<a;i++){
		var=Budget[i].index;
		if(array[var].budget==-1){
		/* Unknown budgets are marked with -1 */
		printf("Unknown %.1lf %s %s %d\n",array[var].score,array[var].name,sample[array[var].genre],array[var].year);
		}
		else{
		printf("%.1lf %lf %s %s %d\n",Budget[i].budget,array[var].score,array[var].name,sample[array[var].genre],array[var].year);	
		}
	}
}
/* this function orders the scores in ascending order */
void orderScore(movie* array,double start_score,double end_score,int l,score_s* Score,char sample[20][20]){
	int i,a=0,k;
	double tempy;
	int var;
	int temp;
	for(i=0;i<l;i++){ 
	tempy=(double) array[i].score;
		if((start_score<=tempy) && (tempy<=end_score)){/* we are searching for the movies with score which between in the 
		user inputs */
				Score[a].score=array[i].score;
				Score[a].index=i;
				/* when we find them, we have to save their index(we are they in the movie order) in related
				struct */
				Score[a].order=i;
				a++;/* counts the movies which are in the interval */
		}
	}
	asc_sort2(a,Score);/* after we determine the movies, we are sorting them in ascending order ac.to score */
	for(i=0;i<a;i++){
		var=Score[i].index;
		if(array[var].budget==-1){
		/* Unknown budgets are marked with -1 */
		printf("unknown %.1lf    %s %s %d\n",array[var].score,array[var].name,sample[array[var].genre],array[var].year);
		}
		else{
			/* other movies are printed as usual */
		printf("%.1lf %lf %s %s %d\n",array[var].budget,array[var].score,array[var].name,sample[array[var].genre],array[var].year);	
		}
	}
}
/* this function orders the genres in ascending order */
void orderGenre(movie* array,double start_genre,double end_genre,int l,genre_s* Genre,char sample[20][20]){
	int i,a=0,k; 
	double tempy;
	int var;
	int temp;
	for(i=start_genre;i<end_genre;i++){ /* we are searching for the movies with genres which between in the 
		user inputs */
			Genre[a].genre=array[i].genre;
			Genre[a].index=i;
				/* when we find them, we have to save their index(we are they in the movie order) in related
				struct */
			Genre[a].order=i;
			a++;/* counts the movies which are in the interval */
		}
	asc_sort3(a,Genre);/* after we determine the movies, we are sorting them in ascending order ac.to score */
	for(i=0;i<a;i++){
		var=Genre[i].index;
		if(array[var].budget==-1){
				/* Unknown budgets are marked with -1 */
		printf("unknown %.1lf %s %s %d\n",array[var].score,array[var].name,sample[array[var].genre],array[var].year);
		}
		else{
		printf("%.1lf %lf %s %s %d\n",array[var].budget,array[var].score,array[var].name,sample[array[var].genre],array[var].year);	
		}
	}
}
void orderYear(movie* array,double start_year,double end_year,int l,year_s* Year,char sample[20][20]){
	int i,a=0,k;
	double tempy;
	int var;
	int temp;
	for(i=0;i<l;i++){ 
	tempy=(double) array[i].year;
		if((start_year<=tempy) && (tempy<=end_year)){
			/* we are searching for the movies with years which between in the 
		user inputs */
				Year[a].year=array[i].year;
				Year[a].index=i;
				/* when we find them, we have to save their index(we are they in the movie order) in related
				struct */
				Year[a].order=i;
				a++;/* counts the movies which are in the interval */
		}
	}
	asc_sort(a,Year);/* after we determine the movies, we are sorting them in ascending order ac.to score */
	for(i=0;i<a;i++){
		var=Year[i].index;
		if(array[var].budget==-1){
				/* Unknown budgets are marked with -1 */
		printf("unknown %.1lf %s %s %d\n",array[var].score,array[var].name,sample[array[var].genre],Year[i].year);
		}
		else{
		printf("%.1lf %lf %s %s %d\n",array[var].budget,array[var].score,array[var].name,sample[array[var].genre],Year[i].year);	
		}
	}
}
/* this function orders the years between two given interval with using the same algorith using above*/
void orderYear_2(movie* array,double start_year,double end_year,int l,year_s* Year){
	int i,a=0,k;
	movie* array2= array;
	double tempy;
	int var;
	int temp;
	for(i=0;i<l;i++){ 
	tempy=(double) array2[i].year;
		if((start_year<=tempy) && (tempy<=end_year)){
				Year[a].year=array2[i].year;
				Year[a].index=i;
				Year[a].order=i;
				a++;
		}
	}
	asc_sort(a,Year);
}
/* this function orders the string that user entered for ordering the movies between two intervals */
void orderName(movie* array,char* str,char* str_1,int l,char sample[20][20]){
	int i,a=0,k;
	int var;
	char* temp;
	movie* array_1;
	int index_s,index_e;
	array_1=array;
	for(i=0;i<l;i++){
		if(strcmp(array_1[i].name,str)==0){ /* comparing the names with user input when we find the movie we will save that index*/
			index_s=i;
		}
		else if(strcmp(array_1[i].name,str_1)==0){
			index_e=i; /* same for the other entered string */
		}
	}
	for(i=index_s;i<=index_e;i++){ /* we are removing the spaces of the strings to order alphabetically */
		removeSpaces(array[i].name); 
	}
	a=index_e-index_s+1;
	orderStrings_1(a,array_1,index_s,index_e);
	for(i=index_s;i<=index_e;i++){ 	
	if(array_1[i].budget==-1){
		printf("unknown %.1lf %s %s %d\n",array_1[i].score,array_1[i].name,sample[array_1[i].genre],array_1[i].year);
		}
		else{
		printf("%.1lf %lf %s %s %d\n",array_1[i].budget,array_1[i].score,array_1[i].name,sample[array_1[i].genre],array_1[i].year);		
		}
	}
}
void menu2(char sample[20][20]){ /* this fucntion prints all the genre types */
	int i;
	for(i=0;i<20;i++){
			printf("%s\n",sample[i]); 
		}
}
int countDigits(int n){
	int count=0; /* this function calculates the digit number with dividing the number at each iteration by ten */
	   while(n!=0)  
   {  
       n=n/10;  
       count++;  
   } 
   return count;
}
/* this function lists all the data when user enter 1 and calls the related functions */
/* in this function we are printing the menu and calling the functions above */
void listallData(movie* arr,char sample [20][20],int l,int len){
	/* we are creating struct pointers for each data type for the number of movies in the txt file */
	budget_s* Budget = (budget_s*) calloc(l,sizeof(budget_s));
	year_s* Year = (year_s*) calloc(l,sizeof(year_s));
	score_s* Score = (score_s*) calloc(l,sizeof(year_s));
	genre_s* Genre = (genre_s*) calloc(l,sizeof(genre_s));
	int i,n,k,a,z;
	double t;
	char* str = (char*) malloc(len*sizeof(char)); /* this char* to using transforming genres to string */
	char* str_1 = (char*) malloc(len*sizeof(char)); 
	double p,m;
	printf("1.Budget\n");
	printf("2.Genre\n");
	printf("3.Name\n");
	printf("4.Score\n");
	printf("5.Year\n");
	printf("Please select an operation: ");
	scanf("%d",&n);
	if(n==1){
		printf("1.Single Selection\n");
		printf("2.Multiple Selection\n");
		printf("Please select an operation: ");
		scanf("%d",&k);
		if(k==1){
			printf("Enter the value: ");
			scanf("%d",&z);
			printf("\n %d.Movie \n",z);
			z-=1;
			if(arr[z].budget==-1){
				printf("Unknown %s %s %lf %d\n",arr[z].name,sample[arr[z].genre],arr[z].score,arr[z].year);
			}
			printf("%lf %s %s %lf %d",arr[z].budget,arr[z].name,sample[arr[z].genre],arr[z].score,arr[z].year);
		}
		else if(k==2){
			printf("Enter the start value \n");
			scanf("%lf",&p);
			printf("Enter the end value \n");
			scanf("%lf",&m);
			printf("Movies between %.1lf and %.1lf, sorted by year.\n", p,m);
			orderBudget(arr,p,m,l,Budget,sample);
		}
       }
    else if(n==2){
    	printf("1.Single Selection\n");
		printf("2.Multiple Selection\n");
		printf("Please select an operation: ");
		scanf("%d",&k);
			if(k==1){
			fflush(stdin);
			printf("Enter the value: ");
			scanf("%d",&z);
			printf("\n %d.Movie \n",z);
			z-=1;
			if(arr[z].budget==-1){
				printf("Unknown %s %s %lf %d\n",arr[z].name,sample[arr[z].genre],arr[z].score,arr[z].year);
			}
			else
			printf("%lf %s %s %lf %d",arr[z].budget,arr[z].name,sample[arr[z].genre],arr[z].score,arr[z].year);
			}
			else if(k==2){
			fflush(stdin);
			printf("Enter the start value \n");
			scanf("%lf",&p);
			printf("Enter the end value \n");
			scanf("%lf",&m);
			printf("Movies between %lf and %lf, sorted by genre.\n", p,m);
			orderGenre(arr,p,m,l,Genre,sample);
			}
	}
	else if(n==3){
		printf("1.Single Selection\n");
		printf("2.Multiple Selection\n");
		printf("Please select an operation: ");
		scanf("%d",&k);
		if(k==1){
			fflush(stdin);
			printf("Enter the value: ");
			scanf("%d",&z);
			printf("\n %d.Movie \n",z);
			z-=1;
			if(arr[z].budget==-1){
				printf("Unknown %s %s %lf %d\n",arr[z].name,sample[arr[z].genre],arr[z].score,arr[z].year);
			}
			else
			printf("%lf %s %s %lf %d",arr[z].budget,arr[z].name,sample[arr[z].genre],arr[z].score,arr[z].year);
			}
		else if(k==2){
			fflush(stdin);
			printf("Enter the start value \n");
			scanf("%[^\n]s",str);
			fflush(stdin);
			printf("Enter the end value \n");
			scanf("%[^\n]s",str_1);
			printf("Movies between %s and %s, sorted by year.\n", str,str_1);
			orderName(arr,str,str_1,l,sample);
				}
		}
	else if(n==4){
			fflush(stdin);
			printf("1.Single Selection\n");
			printf("2.Multiple Selection\n");
			printf("Please select an operation: ");
			scanf("%d",&k);
			if(k==1){
			printf("Enter the value: ");
			scanf("%d",&z);
			printf("\n %d.Movie \n",z);
			if(arr[z].budget==-1){
				printf("Unknown %s %s %lf %d\n",arr[z].name,sample[arr[z].genre],arr[z].score,arr[z].year);
			}
			else
			printf("%lf %s %s %lf %d\n",arr[z].budget,arr[z].name,sample[arr[z].genre],arr[z].score,arr[z].year);
					}
			else if(k==2)
				{
				printf("Enter the start value \n");
				scanf("%lf",&p);
				printf("Enter the end value \n");
				scanf("%lf",&m);
				printf("Movies between %.1lf and %.1lf, sorted by score.\n", p,m);
				orderScore(arr,p,m,l,Score,sample);
				}
	}
	else if(n==5){
		printf("1.Single Selection\n");
		printf("2.Multiple Selection\n");
		printf("Please select an operation: ");
		scanf("%d",&k);
		if(k==1){
			printf("Enter the value: ");
			scanf("%d",&z);
			printf("\n %d.Movie \n",z);
			if(arr[z].budget==-1){
				printf("Unknown %s %s %lf %d\n",arr[z].name,sample[arr[z].genre],arr[z].score,arr[z].year);
			}
			else
			printf("%lf %s %s %lf %d\n",arr[z].budget,arr[z].name,sample[arr[z].genre],arr[z].score,arr[z].year);
		}
		else if(k==2){
			printf("Enter the start value \n");
			scanf("%lf",&p);
			printf("Enter the end value \n");
			scanf("%lf",&m);
			printf("Movies between %lf and %lf, sorted by year.\n", p,m);
			orderYear(arr,p,m,l,Year,sample);			
			}
	}
	
}
void listYear(movie* arr,int l){ /* movie* arr: all the movies as in the struct pointer l: number of movies */
	/* this function lists the years when user enters a year */
	movie* arr_2= arr;
	int count_y=0;
	int i,j,k,n,index,t,count=0;
	int countp=0;
	int s_index; 
	printf("Please enter a year: ");
	scanf("%d",&n);
	a:
	printf("Until (0) or Since (1) %d ",n); 
	scanf("%d",&k);
	year_s* Year2 = (year_s*) malloc(l*sizeof(year_s));
if(k==0){
	for(i=0;i<l;i++){	/* if user enter 0 , print the movies until that year */
		if(n>=arr[i].year){
			count++; /* calculate the number of movies */
			}
		}
	for(i=0;i<l;i++){ /* then find their index also assign their year and index number to related structs*/
		if(n>=arr[i].year){
		Year2[countp].year= arr[i].year;
    	Year2[countp].index= i;
    	Year2[countp].order= i;
		countp++;
			}
		}
	asc_sort(l,Year2); 
	for(i=0;i<l;i++){
		if(n==Year2[i].year){
			s_index=i;
			break;
		}
	}
	for(i=0;i<l;i++){
		if(n==Year2[i].year){
			s_index=i;
			count_y++;
		}
	}
	
	for(i=0;i<s_index+count_y;i++){
			if(countDigits(Year2[i].year)==4){
			printf("%s %d\n",arr[Year2[i].order].name,arr[Year2[i].order].year);
		} 
	}
	}
else if(k==1){
		for(i=0;i<l;i++){ /* if the year is bigger then the user had been entered then count them */
		if(n<=arr[i].year){
			count++;
			}
		}
	for(i=0;i<l;i++){
		if(n<=arr[i].year){ /* after counting we are indicating that movies */
		Year2[countp].year= arr[i].year;
    	Year2[countp].index= i;
    	Year2[countp].order= i;
		countp++;
			}
		}
	asc_sort(l,Year2);
	for(i=0;i<l;i++){
		if(n==Year2[i].year){
			s_index=i;
			break;
		}
		
	}
		for(i=s_index;i<l;i++){
			if(countDigits(Year2[i].year)==4){
			printf("%s %d\n",arr[Year2[i].order].name,arr[Year2[i].order].year);
		} 
	}
	}
	else{
		printf("Please choose a valid menu!");
		goto a;
	}
	
}
void listScore(movie* arr,int l){
	movie* arr_2= arr;
	int count_y=0;
	int i,j,k,index,t,count=0;
	double n;
	int countp=0;
	int s_index; 
	printf("Please enter a score: ");
	scanf("%lf",&n);
	a:
	printf("Until (0) or Since (1) %.1lf ",n);
	scanf("%d",&k);
	score_s* Score2 = (score_s*) malloc(l*sizeof(score_s));
if(k==0){
	for(i=0;i<l;i++){
		if(n>=arr[i].score){
			count++;
			}
		}
	for(i=0;i<l;i++){
		if(n>=arr[i].score){
		Score2[countp].score= arr[i].score;
    	Score2[countp].index= i;
    	Score2[countp].order= i;
		countp++;
			}
		}
	asc_sort2(l,Score2);
	for(i=0;i<l;i++){
		if(n==Score2[i].score){
			s_index=i;
			break;
		}
	}
	for(i=0;i<l;i++){
		if(n==Score2[i].score){
			s_index=i;
			count_y++;
		}
	}
	
	for(i=0;i<s_index+count_y-1;i++){
			if(Score2[i].score!=0){
			printf("%s %lf\n",arr[Score2[i].order].name,arr[Score2[i].order].score);
		} 
	}
	}
else if(k==1){
	for(i=0;i<l;i++){
		if(n<=arr[i].score){
			count++;
			}
		}
	for(i=0;i<l;i++){
		if(n<=arr[i].score){
		Score2[countp].score= arr[i].score;
    	Score2[countp].index= i;
    	Score2[countp].order= i;
		countp++;
			}
		}
	asc_sort2(l,Score2);
	for(i=0;i<l;i++){
		if(n==Score2[i].score){
			s_index=i;
			break;
		}		
	}
	for(i=s_index;i<l;i++){
			if(Score2[i].score!=0){
			printf("%s %lf\n",arr[Score2[i].order].name,arr[Score2[i].order].score);
			} 
		}
	}
	else{
		printf("Please choose a valid menu!");
		goto a;
	}
}
void allInfo(movie* arr,int l,char sample[20][20]){
	int i,x,index;
	char* temp= (char*) malloc(x*sizeof(char));
	printf("Please enter the name of the movie: ");
	fflush(stdin);
	scanf("%[^\n]s",temp);
	for(i=0;i<l;i++){
		if(strcmp(temp,arr[i].name)==0){
			index=i; /* last index*/
		}
	}
	if(arr[index].budget==-1){
	printf("Budget: Unknown\n");
	}
	else{
	printf("Budget: %lf\n",arr[index].budget);
	}
	printf("Genre: %s\n",sample[arr[index].genre]);
	printf("Name: %s\n",arr[index].name);
	printf("Score: %lf\n",arr[index].score);
	printf("Year: %d\n",arr[index].year);
}
void assigntoStruct(int x,int i,movie* arr,double budget,int genre,char* name1,double score,int year){
	arr[i].name= (char*) malloc(x*sizeof(char));
	strcpy(arr[i].name,name1);
	arr[i].year=year;
	arr[i].budget=budget;
	arr[i].score=score;
	arr[i].genre=genre;
}
int calculateLine(){ /* this function returns the number of lines in given file */
	int n,x,count=0;
	FILE *fp= fopen("Movies.txt","r"); /* Opening the file */
	char* str= (char*)malloc(sizeof(char)*1000); /* for calculating the line number, we choose a big number to allocate */
	while(fgets(str,1000,fp)!=NULL){
		count++;
	}
	fclose(fp);/* closing the file */
	return count;
}
/* this function manages the file and receiving the inputs */
void handleFile(FILE *fp,char* str,movie* arr,int l,int x,char sample [20][20],int* count,double* sum,int* genres){
	int i,a=0,k,flag=0;
	char* b;
	char* t;
	double genre_d;
	double score;
	int genre;
	int year,s;
	double budget;
	char* budget_s= (char*) malloc(x*sizeof(char)); /* temporary array for implementing parse operation */
	char* name= (char*) malloc(x*sizeof(char)); /* temporary array for implementing parse operation */
	char* genre_s= (char*) malloc(x*sizeof(char)); /* temporary array for implementing parse operation */
	fseek(fp,0,SEEK_SET);
	fgets(str,x,fp); /* getting the first line which is not a movie */
	for(i=0;i<l;i++){ /* until reaching the number of movie which is l */
		fgets(str,x,fp); /* start read the file line by line str: buffer for fgets*/
		flag=0; 
		s=sscanf(str,"%[^,],%[^,], %[^,] , %lf, %d", budget_s,genre_s,name,&score,&year);
		/* we are parsing the str by using sscanf */
		if(s!=5) /* if sscanf does not parse the str properly then skip that line */
			goto f;
		*sum=*sum+score;
		*count=*count+1;
		if(strcmp(budget_s,"unknown")==0 || strcmp(budget_s,"Unknown")==0){
			budget=-1;
			/* if the budget is unknown mark it as -1 */
		}
		else{
			sscanf(budget_s,"%lf",&budget);
		}
		if(a==0){
			strcpy(sample[0],genre_s); /* managing the genre. if we are in the first index, make sample[0] is that genre */
			a++;
			genre=0;
		}
		for(k=0;k<20;k++){
			if(strcmp(sample[k],genre_s)==0){ /* if we are not in the first index, compare the sample array if the given 
			genre is already in the list or not */
				genre=k;
				flag=1;
			}
		}
		if(flag==0){
			strcpy(sample[a],genre_s); /* if the genre is not in the list add it to the next index */
			genre=a;
			a++;
		}
		r:
		assigntoStruct(x,i,arr,budget,genre,name,score,year); /* assign all the parsed info to the related movie's struct
		and call the next movie in the for loop */
		f:;
		genres[i]=genre;
	}
	free(str);
	free(budget_s);
	free(genre_s);
	free(name);
}
int listGenres(movie* arr,int l,int* genres,int k){
	/* this program lists all the genres in the list */
	int i,counter=0;
	for(i=0;i<l;i++){
		if(k==genres[i]){
			counter++;
		}
	}
	return counter;
}
int terminate(){
	/* this function is terminating the program if user enter 0 as an input */
	int n;
	printf("\nDo you want to continue? YES(1) or NO(0) ");
	scanf("%d",&n);
	if(n==1){
		return 1;
	}
	else{
		exit(1);
	}
}
void printMenu(int *n){ /* Printing the menu to the panel */
	int scanf_control;
	printf("1. List of the Sorted Data\n");
	printf("2. List of the Genres\n");
	printf("3.List of the Movie Through the Years\n");
	printf("4.List of the Movie Through the Scores\n");
	printf("5.All Informations of a Single Movie\n");
	printf("6.Avarage of the IMDB Scores\n");
	printf("7.Frequence of the Genres\n");
	printf("8.Exit\n");
	printf("\nPlease Select an Operation: ");
	scanf_control=scanf("%d",&(*n)); /* scanning the menu option */
	if(*n>8||*n<1||scanf_control!=1){
	printf("Try Again! \n"); /* if the menu option is not in the interval or a char printf error message */
	}
}
void calculateAv(movie* arr,int l,int* count,double* sum){
	/* this function calculates the avarage of the imdb scores */
	int i;
	double avarage;
	avarage= (double) (*sum/ (double)*count);
	printf("Avarage of the IMDB scores is : %lf",avarage);
}

int  main(){
	int n,l,i,len1,len=0,x=0;
	int count=0;
	char ch;
	int ret;
	double sum=0;
	char* temp_p;
	FILE *fp= fopen("Movies.txt","r"); /* Opening the file */
	while((ch=fgetc(fp))!=EOF) { /* finding the number of characters in a line */
		x++;
	}
	fseek(fp,SEEK_SET,0); /* carrying cursor at the start point */
	l=calculateLine(); /* calculating the number of lines in the file */
	int* genres= (int*) malloc(l*sizeof(int*));
	char sample[20][20]; /* array that holds the genres */
	char* str= (char*) malloc(x*sizeof(char)); /* char* which reads the whole line in the file */
	movie* arr= (movie*) malloc(l*sizeof(movie)); /* struct pointer(struct array) which holds the movies inside of it */
	handleFile(fp,str,arr,l,x,sample,&count,&sum,genres);
	len1= sizeof(sample)/sizeof(sample[0]);
	if(fp==NULL){ /* if the file cannot be opened give an error message */
		printf("Error opening the file");
		exit(1);
	}
	do{
	printMenu(&n); /* Printing the menu to the panel */
	switch(n){
		case 1:
			listallData(arr,sample,l,len1);
			break;
		case 2:
			menu2(sample);
			break;
		case 3:
			listYear(arr,l);
			break;
		case 4:
			listScore(arr,l);
			break;
		case 5:
			allInfo(arr,l,sample);
			break;
		case 6:
			calculateAv(arr,l,&count,&sum);
			break;
		
		case 7:
			for(i=0;i<len1;i++){
				ret=listGenres(arr,l,genres,i);
				if(ret!=0)
				printf("%s %d\n",sample[i],ret);
			}
			break;
		
		 default:
			printf("Please enter a valid input!");
		}
	} 
	while(terminate()==1);
	free(str);
	free(genres);
	fclose(fp);/* closing the file */
	return 0;
}
