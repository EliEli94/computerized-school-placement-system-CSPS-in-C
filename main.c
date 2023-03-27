#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
	
	int opt,option;
	struct result rslt;
	struct result rslts;
	struct categories cat1;
	struct categories cat2;
	struct categories cat3;

	int aggregate,searchResult=0;
	int i,j,k,l,m;
	char name[50];
	char saveResult = 'y';
	FILE *fp;
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	
//struct for schools
struct schools{
	char schoolName[30];
	int cutoff;
};
struct categories{
	struct schools type[10];
};
//struct for results
struct subjects{
	unsigned int grade;
};
struct result{
	char student[10];
	unsigned int idNum;
	char choice[4][30];
	struct subjects  sub[10];
};
char remark[9][20];
char remarks[9][20] = {"Excelent","Very Good","Good","Credit","Credit","Credit","Pass","Poor","Fail"};
char subject[9][20] = {"English","Maths","Studies","Science","Gh.Lang","RME","French","ICT","BDT"};	

//functions Declaration
void schoolsHeader();
void allSchools();
void schoolsBody();
void studentResultHeader();	
void generateResultBody();
void generateResultFooter();
void enterResult();
void readResult();
void search();

//functions definition
void studentResultHeader(char name[50],unsigned int id){
	printf("\n\n");
	printf("\t Students\' Results");
	printf("\nName: %s",name);
	printf("\nIndex Number: %d",id);
	printf("\n------------------------------------------------------\n");
	printf("Subject\t\t\t");
	printf("Grade\t\t");
	printf("Remarks\t\t\t");
	printf("\n------------------------------------------------------\n");
	printf("\n\n");
}
void generateResultBody(char subject[10], unsigned int grade, char remark[10]){
	printf("%s\t\t\t",subject);
	printf("%d\t\t",grade);
	printf("%s",remark);
	printf("\n");
}
void generateResultFooter(unsigned int aggregate, char school[4]){
	printf("\n------------------------------------------------------\n");
	printf("\nAggregate\t\t");
	printf("%d\n",aggregate);
	printf("School\t\t %s",school);
	printf("\n------------------------------------------------------\n");	

}
void allSchools(){
//		//category A schools
//				strcpy(cat1.type[0].schoolName ,"Mawuli School");
//				cat1.type[0].cutoff = 9;
//				strcpy(cat1.type[1].schoolName ,"Keta SHS");
//				cat1.type[1].cutoff = 10;
//				strcpy(cat1.type[2].schoolName ,"Aggrey Memorial");
//				cat1.type[2].cutoff = 12;
//				strcpy(cat1.type[3].schoolName ,"Achimota SHS");
//				cat1.type[3].cutoff = 13;
//				
//				//catergory B schools
//				strcpy(cat2.type[0].schoolName ,"Prempeh College");
//				cat2.type[0].cutoff = 15;
//				strcpy(cat2.type[1].schoolName ,"Ada SHS");
//				cat2.type[1].cutoff = 18;
//				strcpy(cat2.type[2].schoolName ,"Opoku Ware SHS");
//				cat2.type[2].cutoff = 20;
//				strcpy(cat2.type[3].schoolName ,"PRESEC Legon");
//				cat2.type[3].cutoff = 19;
//				
//				//category C schools
//				strcpy(cat3.type[0].schoolName ,"Wesley Girls");
//				cat3.type[0].cutoff = 25;
//				strcpy(cat3.type[1].schoolName ,"Adisadel College");
//				cat3.type[1].cutoff = 30;
//				strcpy(cat3.type[2].schoolName ,"Nkranza SHS");
//				cat3.type[2].cutoff = 40;
//				strcpy(cat3.type[3].schoolName ,"KNUST SHS");
//				cat3.type[3].cutoff = 54;
//				
//				fp = fopen("catA.txt","w");
//					fwrite(&cat1,sizeof(struct categories),1,fp);
//					if(fwrite != 0)
//					printf("Succesfully saved\n");
//					else
//					printf("Error Saving schools\n"); 
//					fclose(fp);
//				fp = fopen("catB.txt","w");
//					fwrite(&cat2,sizeof(struct categories),1,fp);
//					if(fwrite != 0)
//					printf("Succesfully saved\n");
//					else
//					printf("Error Saving schools\n"); 
//					fclose(fp);
//				fp = fopen("catC.txt","w");
//					fwrite(&cat3,sizeof(struct categories),1,fp);
//					if(fwrite != 0)
//					printf("Succesfully saved\n");
//					else
//					printf("Error Saving schools\n"); 
//					fclose(fp);
//					
			int n =0;
			fp = fopen("catA.txt","r");
			printf("\n ******Category A Schools******\n");
			while(fread(&cat1,sizeof(struct categories),1,fp)){
				schoolsHeader();
				for(n=0;n<4;n++){
					schoolsBody(cat1.type[n].schoolName,cat1.type[n].cutoff);
				}
			} 
			fp = fopen("catB.txt","r");
			printf("\n ******Category B Schools******\n");
			while(fread(&cat2,sizeof(struct categories),1,fp)){
				schoolsHeader();
				for(n=0;n<4;n++){
					schoolsBody(cat2.type[n].schoolName,cat2.type[n].cutoff);
				}
			} 
			fp = fopen("catC.txt","r");
			printf("\n ******Category C Schools******\n");
			while(fread(&cat3,sizeof(struct categories),1,fp)){
				schoolsHeader();
				for(n=0;n<4;n++){
					schoolsBody(cat3.type[n].schoolName,cat3.type[n].cutoff);
				}
			} 
	
			fclose(fp);
}
void schoolsHeader(){
	printf("\n-------------------------------------------\n");
	printf("School Name\t\t\t");
	printf("Cut-off\t\t\t");
	printf("\n-------------------------------------------\n\n");
}
void schoolsBody(char schName[30], int cutoff){
	printf("%s\t\t\t",schName);
	printf("%d",cutoff);
	printf("\n");
}
void enterResult(){
		printf("\n\tEnter Name of Student:\t");
		fgets(rslt.student,50,stdin);
		int i = 0;
		rslt.student[strlen(rslt.student)-1] = 0;
		for(i=0;rslt.student[i]!='\0';i++){
			rslt.student[i]=toupper(rslt.student[i]);
		}
		printf("\n\tEnter Index Number:");
		scanf("%d",&rslt.idNum);
		printf("\n\tEnter Results");
			
		for(j=0;j<9;j++){
			printf("\n%s\t",subject[j]);
			scanf("%d",&rslt.sub[j].grade);
			if(rslt.sub[j].grade == 1){
				strcpy(remark[j],remarks[0]);
			}
			else if(rslt.sub[j].grade == 2){
				strcpy(remark[j],remarks[1]);
			}
			else if(rslt.sub[j].grade == 3){
				strcpy(remark[j],remarks[2]);
			}
			else if(rslt.sub[j].grade == 4){
				strcpy(remark[j],remarks[3]);
			}
			else if(rslt.sub[j].grade == 5){
				strcpy(remark[j],remarks[4]);
			}
			else if(rslt.sub[j].grade == 6){
				strcpy(remark[j],remarks[5]);
			}
			else if(rslt.sub[j].grade == 7){
				strcpy(remark[j],remarks[6]);
			}
			else if(rslt.sub[j].grade == 8){
				strcpy(remark[j],remarks[7]);
			}
			else{
				strcpy(remark[j],remarks[8]);
			}
		}
		while(k<4){
					aggregate += rslt.sub[k].grade;
					k++;
				}
			
			//arranging electives in ascending order
				int y,temp = 0;
				int tempArr[5];
				for(y=0;y<5;++y){
					tempArr[y] = rslt.sub[y+4].grade;
				}
			for(k=0;k<5;++k){
				for(l=k+1;l<5;++l){
					if(tempArr[k]>tempArr[l]){
						temp = tempArr[k];
						tempArr[k] = tempArr[l];
						tempArr[l] = temp;
					}	
				}
			}
			aggregate += tempArr[0]+tempArr[1];
				system("cls");
					//School selection
//					cat A
				printf("School Selection\n");
				int choice1=0,choice2=0,choice3=0,choice4=0;
				fp1 = fopen("catA.txt","r");
				fp2 = fopen("catB.txt","r");
				fp3 = fopen("catC.txt","r");
				printf("Select a school from this category\n");
				printf("==Category A==\n");
				while(fread(&cat1,sizeof(struct categories),1,fp1)){
					int n=0;
					for(n=0;n<4;n++){
						printf("%d. %s\n",n+1,cat1.type[n].schoolName);
					}
				}
				scanf("%d",&choice1);
				//cat B 
				printf("Select a school from this category\n");
				printf("==Category B==\n");
				while(fread(&cat2,sizeof(struct categories),1,fp2)){
					int n=0;
					for(n=0;n<4;n++){
						printf("%d. %s\n",n+1,cat2.type[n].schoolName);
					}
				}
				scanf("%d",&choice2);
//				cat C
				printf("Select two schools from this category\n");
				printf("==Category C==\n");
				while(fread(&cat3,sizeof(struct categories),1,fp3)){
					int n=0;
					for(n=0;n<4;n++){
						printf("%d. %s\n",n+1,cat3.type[n].schoolName);
					}
				}
				scanf("%d %d",&choice3, &choice4);
				
				//assigning Schools
				if(aggregate<=cat1.type[choice1-1].cutoff){
						strcpy(rslt.choice,cat1.type[choice1-1].schoolName);
					}
					else if(aggregate<=cat2.type[choice2-1].cutoff){
						strcpy(rslt.choice,cat2.type[choice2-1].schoolName);
					}
					else if(aggregate<=cat3.type[choice3-1].cutoff){
						strcpy(rslt.choice,cat3.type[choice3-1].schoolName);
					}
					else if(aggregate<=cat3.type[choice4-1].cutoff){
						strcpy(rslt.choice,cat3.type[choice4-1].schoolName);
					}
					else{
						strcpy(rslt.choice,"No school assigned");
					}
					system("cls");
			printf("===Your Choice of Schools===\n");
			printf("1. %s\n2. %s\n3. %s\n4. %s\n\n",cat1.type[choice1-1].schoolName,cat2.type[choice2-1].schoolName,cat3.type[choice3-1].schoolName,cat3.type[choice4-1].schoolName);
			//displaying the summary of the results
			studentResultHeader(rslt.student,rslt.idNum);
			for(i=0;i<9;i++){
				generateResultBody(subject[i],rslt.sub[i].grade,remark[i]);
			}
				generateResultFooter(aggregate,rslt.choice);
			//saving results
				printf("Do you want to save the results? (y/n)\n");
				scanf("%s",&saveResult);
				if(saveResult == 'y'){
					fp = fopen("ResultsPortal.txt","a+");
					fwrite(&rslt,sizeof(struct result),1,fp);
					if(fwrite != 0)
					printf("Succesfully saved\n");
					else
					printf("Error Saving result\n"); 
					fclose(fp);
				}
}
void readResult(){
	fp = fopen("ResultsPortal.txt","r");
			printf("\n ******Saved Results******\n");
			
			while(fread(&rslt,sizeof(struct result),1,fp)){
					int agg=0;
				 studentResultHeader(rslt.student,rslt.idNum);

				for(i=0;i<9;i++){
				
						if(rslt.sub[i].grade == 1){
							strcpy(remark[i],remarks[0]);
						}
						else if(rslt.sub[i].grade == 2){
								strcpy(remark[i],remarks[1]);
						}
						else if(rslt.sub[i].grade == 3){
							strcpy(remark[i],remarks[2]);
						}
						else if(rslt.sub[i].grade == 4){
							strcpy(remark[i],remarks[3]);
						}
						else if(rslt.sub[i].grade == 5){
							strcpy(remark[i],remarks[4]);
						}
						else if(rslt.sub[i].grade == 6){
							strcpy(remark[i],remarks[5]);
						}
						else if(rslt.sub[i].grade == 7){
							strcpy(remark[i],remarks[6]);
						}
						else if(rslt.sub[i].grade == 8){
							strcpy(remark[i],remarks[7]);
						}
						else{
							strcpy(remark[i],remarks[8]);
				}
					generateResultBody(subject[i],rslt.sub[i].grade,remark[i]);
					agg = rslt.sub[0].grade+rslt.sub[1].grade+rslt.sub[2].grade+rslt.sub[3].grade;
				} 
				//arranging electives in ascending order
				int y,temp = 0;
				int tempArr[5];
				for(y=0;y<5;++y){
					tempArr[y] = rslt.sub[y+4].grade;
				}
			for(k=0;k<5;++k){
				for(l=k+1;l<5;++l){
					if(tempArr[k]>tempArr[l]){
						temp = tempArr[k];
						tempArr[k] = tempArr[l];
						tempArr[l] = temp;
					}	
				}
			}
			agg += tempArr[0]+tempArr[1];
				generateResultFooter(agg,rslt.choice);
			}
			fclose(fp);
}
void search(){
	case3:
	printf("\nEnter name of student:\t");
				fgets(name,50,stdin);
				name[strlen(name)-1] = 0;
				for(i=0;name[i]!='\0';i++){
					name[i]=toupper(name[i]);
				}
				fp = fopen("ResultsPortal.txt","r");
				printf("\n******Student\'s Results and Placement******\n");				
				while(fread(&rslts,sizeof(struct result),1,fp)){
					int agg=0;			
					if(!strcmp(rslts.student,name)){
						studentResultHeader(rslts.student,rslts.idNum);
					for(i=0;i<9;i++){
							if(rslts.sub[i].grade == 1){
								strcpy(remark[i],remarks[0]);
							}
							else if(rslts.sub[i].grade == 2){
								strcpy(remark[i],remarks[1]);
							}
							else if(rslts.sub[i].grade == 3){
								strcpy(remark[i],remarks[2]);
							}
							else if(rslts.sub[i].grade == 4){
								strcpy(remark[i],remarks[3]);
							}
							else if(rslts.sub[i].grade == 5){
								strcpy(remark[i],remarks[4]);
							}
							else if(rslts.sub[i].grade == 6){
								strcpy(remark[i],remarks[5]);
							}
							else if(rslts.sub[i].grade == 7){
								strcpy(remark[i],remarks[6]);
							}
							else if(rslts.sub[i].grade == 8){
								strcpy(remark[i],remarks[7]);
							}
							else{
								strcpy(remark[i],remarks[8]);
							}
						generateResultBody(subject[i],rslts.sub[i].grade,remark[i]);
					agg = rslts.sub[0].grade+rslts.sub[1].grade+rslts.sub[2].grade+rslts.sub[3].grade;
					} 
					//arranging electives in ascending order
				int y,temp = 0;
				int tempArr[5];
				for(y=0;y<5;++y){
					tempArr[y] = rslts.sub[y+4].grade;
				}
			for(k=0;k<5;++k){
				for(l=k+1;l<5;++l){
					if(tempArr[k]>tempArr[l]){
						temp = tempArr[k];
						tempArr[k] = tempArr[l];
						tempArr[l] = temp;
					}	
				}
			}
			agg += tempArr[0]+tempArr[1];
					generateResultFooter(agg,rslts.choice[0]);
					searchResult = 1;
					}
				}
				if(!searchResult){
					
							printf("Student\'s results not in our database.\n1 Search again\n2 Previous Menu\n3 Exit\n");
							scanf("%d",&option);
							if(option == 1){
								goto case3;
							}
							else if(option == 2){
								main();
							}else{
								exit(0);
							}		
				}
				fclose(fp);
}
int main(int argc, char *argv[]) {
	//dashboard
	menu:
	system("cls");
	printf("\t===========Computerised School Placement System (CSPS)===========");
	printf("\n\n1. Upload Results");
	printf("\n2. Saved Results");
	printf("\n3. Check Results");
	printf("\n4. All Schools");
	printf("\n5. Exit");
	printf("\n\n\t Please select an option:\t");
	scanf("%d",&opt);
	fgetc(stdin);
	switch(opt){
		case 1:
			system("cls");
			enterResult();			
			break;	
		case 2:
			system("cls");
			readResult();
			printf("\n1. Previous Menu\n2. Exit\n");
			scanf("%d",&option);
			if(option == 1){
				goto menu;
			}
			else{
				exit(0);
			}
			break;
		case 3:
			system("cls");
			search();
			break;
		case 4:
			system("cls");
			allSchools();
			printf("\n1. Previous Menu\n2. Exit\n");
			scanf("%d",&option);
			if(option == 1){
				goto menu;
			}
			else{
				exit(0);
			}
			break;
		case 5:
			exit(0);
		defaut:
			printf("Invalid Input");
			exit(0);
	}
		
	return 0;
}
