#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Bhavik=0; //No. of nodes
struct node { //node creation
	struct node *left; //path towards previous node (contact)
	char oname[20]; //stores the name (can store a maximum of 20 letters for each name)
	char nick[20]; //if available, stores the nick name (can store a maximum of 20 letters for each nick name)
	int age; //stores the age
	int no[20]; //stores the telephone number (can store a maximum of 20 numbers for each contact/name)
	int alt; //stores 0 if the nick name is not available and 1 if the nick name is available
	int count; //stores number of telephone numbers for each contact/name (starts from 0)
	struct node *right; //path towards next node (contact)
};
struct node *head=NULL; //declaration of head which will always point towards the first node (contact)
void main() {
	FILE *fptr;// reading the contents of the file
	fptr=fopen("FILE.c","r");
	int jai=0,ram=0; //jai is used to count the number of lines of the file and ram is used to match each line
	char ch=getc(fptr),bname[5];
	while(ch!=EOF) {
		if(ch=='\n')
			jai++; //counting of each line 
		ch=getc(fptr);
	}
	rewind(fptr);
	if(jai!=0) //when the file is not null, last 2 (useless) lines are subtracted from the file 
		jai=jai-2;
	while(ram!=jai) {
		for(ch=getc(fptr);ch!='\n';ch=getc(fptr)) { //eliminating the new line
		}
		ram++; //increasing the line count
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		int day=0,night=-1; //used to store 0 or 1 if the nick name exists and to store the number of telephone number for the contact
		while(1) {
			for(int i=0;i<4;i++) {
				ch=getc(fptr);
				bname[i]=ch; //storing the first four letters of the line
			}
			if(strcmp(bname,"Name")==0) { //checking for the possiblity if "Name" is available
				for(int i=0;i<2;i++) {
					for(ch=getc(fptr);ch!=' ';ch=getc(fptr)) { //eliminating the = sign
					}
				}
				for(int i=0,ch=getc(fptr);ch!='\n';i++,ch=getc(fptr)) {
					temp->oname[i]=ch; //storing the name
				}
				ram++; //increasing the line count
			}
			else if(strcmp(bname,"Nick")==0) { //checking for the possiblity if "Nick name" is available
				for(int i=0;i<3;i++) {
					for(ch=getc(fptr);ch!=' ';ch=getc(fptr)) { //eliminating the = sign
					}
				}
				for(int i=0,ch=getc(fptr);ch!='\n';i++,ch=getc(fptr)) {
					temp->nick[i]=ch; //storing the nick name
				}
				day++; //storing 1 as a sign of nick name existing
				ram++; //increasing the line count
			}
			else if(strcmp(bname,"Age ")==0) {
				int val=0,a=0;
				char bage[3],str[3];
				for(ch=getc(fptr);ch!=' ';ch=getc(fptr)) { //eliminating the = sign
				}
				for(int i=0,ch=getc(fptr);ch!='\n';i++,a++,ch=getc(fptr)) {
					bage[i]=ch; //storing the age (in char form)
				}
				strcpy(str,bage);
				for(int i=0;i<a;i++)
        				val=val*10+str[i]-'0'; //converting the age into int form
				temp->age=val;
				ram++; //increasing the line count
			}
			else if(strcmp(bname,"Tele")==0) { //checking for the possiblity if "Tele" is available
				do {
					for(int i=0;i<4;i++)
						ch=getc(fptr);
					for(int i=0;i<4;i++) {
						ch=getc(fptr);
						bname[i]=ch;  //storing the third four letters of the line
					}
					if(strcmp(bname,"e nu")!=0) //checking if the line has the telephone number and is not the last line of the specific contact
						break;
					night++; //storing the telephone number count
					int val=0;
					char bno[7],str[7];
					for(int i=0;i<3;i++) {
						for(ch=getc(fptr);ch!=' ';ch=getc(fptr)) { //eliminating the useless content
						}
					}
					for(int i=0,ch=getc(fptr);ch!='\n';i++,ch=getc(fptr)) { //storing the telephone number (in char form)
						bno[i]=ch;
					}
					strcpy(str,bno);
					for(int i=0;i<7;i++)
	        				val=val*10+str[i]-'0'; //converting the telephone number into int form
					temp->no[night]=val;
					for(int i=0;i<4;i++) {
						ch=getc(fptr);
						bname[i]=ch;  //storing the first four letters of the line
					}
					ram++; //increasing the line count
				}while(strcmp(bname,"Tele")==0);
				for(ch=getc(fptr);ch!='\n';ch=getc(fptr)) {
				}
				ram++; //increasing the line count
				temp->alt=day; //used to store 0 or 1 if the nick name exists
				temp->count=night; //used to store the number of telephone number for the contact
				if(head==NULL) { //if the first node is formed and to be attached
					temp->left=temp->right=NULL;
					head=temp;
				}
				else { //to attach at the last node
					struct node *x=head;
					while(x->right!=NULL)
						x=x->right; //to find the last node
					temp->left=x;
					temp->right=NULL;
					x->right=temp;
				}
				Bhavik++; //incrementing the number of nodes
				break;
			}
		}
	}
	fclose(fptr);
	while(1) {
		int n;
		printf("\n--------1.Insert a contact/telephone number     --------\n--------2.Delete an contact/telephone number    --------\n--------3.Display the directory/specific contact--------\n--------4.Exit                                  --------\n    Enter your choice 😄️ : ");
		scanf("%d",&n);
		switch(n) {
			case 1: {
				int x;
				printf("\n    ----1.Insert a new contact         ----\n    ----2.Insert a new telephone number----\n  Enter your choice 😄️ : ");
				scanf("%d",&x);
				switch(x) {
					case 1: {
						int hello=0,tom,s=1,apple=0;
						struct node *temp=(struct node *)malloc(sizeof(struct node));
						printf("Enter the name : ");
						while(1) {
							int song=0;
							scanf("%s",temp->oname);
							struct node *b=head;
							while(b!=NULL) {
								if(strcmp(b->oname,temp->oname)==0) {
									printf("%s already exists in the directory\nDo you have another contact to be added(1/0) : ",temp->oname);
									scanf("%d",&s);
									while(s!=0&&s!=1) {
										printf("Enter 1 if true or 0 if false : ");
										scanf("%d",&s);
									}
									if(s==1) {
										printf("Enter another name : ");
										song++;
									}
									break;
								}
								b=b->right;
							}
							if(song==0)
								break;
						}
						if(s==0)
							break;
						printf("Does %s have a nick name(1/0) : ",temp->oname);
						scanf("%d",&temp->alt);
						while(temp->alt!=0&&temp->alt!=1) {
							printf("Enter 1 if true or 0 if false : ");
							scanf("%d",&temp->alt);
						}
						if(temp->alt==1) {
							printf("Enter the nick name : ");
							scanf("%s",temp->nick);
						}
						printf("Enter the age : ");
						scanf("%d",&temp->age);
						temp->count=-1;
						while(1) {
							temp->count++;
							while(1) {
								printf("Enter the telephone number to be added : ");
								scanf("%d",&temp->no[temp->count]);
								int eye=0,dno=temp->no[temp->count],song=0;
								while(dno!=0) {
									dno=dno/10;
									eye++;
								}
								while(eye!=7) {
									printf("Enter a seven digit telephone number : ");
									scanf("%d",&temp->no[temp->count]);
									eye=0,dno=temp->no[temp->count];
									while(dno!=0) {
										dno=dno/10;
										eye++;
									}
								}
								struct node *b=head;
								while(song==0&&apple==0&&b!=NULL) {
									for(int i=0;i<=b->count;i++) {
										if(b->no[i]==temp->no[temp->count]) {
											printf("The telephone number %d already exists in %s's contact\nDoes %s have another telephone number to be added(1/0) : ",temp->no[temp->count],b->oname,temp->oname);
											scanf("%d",&s);
											while(s!=0&&s!=1) {
												printf("Enter 1 if true or 0 if false : ");
												scanf("%d",&s);
											}
											if(s==1)
												song++;
											else if(s==0) {
												if(temp->count==0)
													printf("The contact was not saved as the telephone number does not exist\n");
												apple++;
											}
											break;
										}
									}
									b=b->right;
								}
								if(song==0&&apple==0&&temp->count!=0) {
									for(int i=0;i<temp->count;i++) {
										if(temp->no[i]==temp->no[temp->count]) {
											printf("Please do not enter the same telephone number again\nDoes %s have another telephone number to be added(1/0) : ",temp->oname);
											scanf("%d",&s);
											while(s!=0&&s!=1) {
												printf("Enter 1 if true or 0 if false : ");
												scanf("%d",&s);
											}
											if(s==1)
												song++;
											else if(s==0) {
												if(temp->count==0)
													printf("The contact was not saved as the telephone number does not exist\n");
												apple++;
											}
											break;
										}
									}
								}
								if(song==0)
									break;
							}
							if(s==0)
								break;
							if(s==1) {
								printf("Does %s have another telephone number to be added(1/0) : ",temp->oname);
								scanf("%d",&s);
								while(s!=0&&s!=1) {
									printf("Enter 1 if true or 0 if false : ");
									scanf("%d",&s);
								}
								if(s==0)
									break;
							}
						}
						if(apple!=0&&temp->count==0)
							break;
						printf("All the details of %s have been saved at a section of the directory 😁️\n",temp->oname);
						Bhavik++;
						if(head==NULL) {
							temp->left=temp->right=NULL;
							head=temp;
						}
						else {
							struct node *x=head;
							if(strcmp(temp->oname,head->oname)<0) {
								temp->left=NULL;
								temp->right=head;
								head->left=temp;
								head=temp;
								hello++;
							}
							else {
								while(x->right!=NULL) {
									x=x->right;
									if(strcmp(temp->oname,x->oname)<0) {
										struct node *p=x->left;
										temp->left=p;
										temp->right=x;
										x->left=temp;
										p->right=temp;
										hello++;
										break;
									}
								}
							}
							if(hello==0) {
								temp->left=x;
								temp->right=NULL;
								x->right=temp;
							}
						}
						FILE *fptr;
						fptr=fopen("similar.c","w");
						struct node *x=head;
						while(x!=NULL) {
							int fage=x->age,fno[20],fcount=x->count,kite=strlen(x->oname);
							char fname[20],fnick[20];
							for(int i=0;i<=kite;i++)
								fname[i]=x->oname[i];
							fprintf(fptr,"\nName = %s\n",fname);
							if(x->alt==1) {
								int jerry=strlen(x->nick);
								for(int i=0;i<=jerry;i++)
									fnick[i]=x->nick[i];
								fprintf(fptr,"Nick name = %s\n",fnick);
							}
							fprintf(fptr,"Age = %d\n",fage);
							for(int i=0;i<=x->count;i++) {
								fno[i]=x->no[i];
								fprintf(fptr,"Telephone number [%d] = %d\n",i+1,fno[i]);
							}
							if(x->count==0)
								fprintf(fptr,"%s has 1 Telephone number\n",fname);
							else
								fprintf(fptr,"%s has %d Telephone numbers\n",fname,fcount+1);
							x=x->right;
						}
						if(Bhavik==1)
							fprintf(fptr,"\nThere is 1 contact available in the directory\n");
						else
							fprintf(fptr,"\nThere are %d contacts available in the directory\n",Bhavik);
						remove("FILE.c");
						rename("similar.c","FILE.c");
						printf("The file is edited\n");
						fclose(fptr);
					}
					break;
					case 2: {
						if(head==NULL) {
							printf("-The directory is empty-\n");
							break;
						}
						int y;
						printf("\n  --1.Insert the telephone number using the name of the person       --\n  --2.Insert the telephone number using the existing telephone number--\n Enter your choice 😄️ : ");
						scanf("%d",&y);
						switch(y) {
							case 1: {
								int hello=0;
								char dname[20];
								printf("Enter the name of the person, the telephone number must be added to : ");
								scanf("%s",dname);
								struct node *x=head;
								while(hello==0&&x!=NULL) {
									if(strcmp(x->oname,dname)==0) {
										while(1) {
											int s,dno;
											printf("Enter the telephone number to be added : ");
											while(1) {
												scanf("%d",&dno);
												int eye=0,dno1=dno,song=0;
												while(dno1!=0) {
													dno1=dno1/10;
													eye++;
												}
												while(eye!=7) {
													printf("Enter a seven digit telephone number : ");
													scanf("%d",&dno);
													eye=0,dno1=dno;
													while(dno1!=0) {
														dno1=dno1/10;
														eye++;
													}
												}
												struct node *b=head;
												while(song==0&&b!=NULL) {
													for(int i=0;i<=b->count;i++) { 
														if(b->no[i]==dno) {
															printf("The telephone number %d already exists in %s's contact\nEnter another telephone number to be added : ",dno,b->oname);
															song++;
															break;
														}
													}
													b=b->right;
												}
												if(song==0)
													break;
											}
											x->count++;
											x->no[x->count]=dno;
											hello++;
											printf("The %d telephone number is added to %s's contact\n",x->no[x->count],x->oname);
											printf("Does %s have another telephone number to be added(1/0) : ",x->oname);
											scanf("%d",&s);
											while(s!=0&&s!=1) {
												printf("Enter 1 if true or 0 if false : ");
												scanf("%d",&s);
											}
											if(s==0)
												break;
										}
									}
									x=x->right;
								}
								if(hello==0)
									printf("%s does not exist in the directory\n",dname);
								else {
									FILE *fptr;
									fptr=fopen("similar.c","w");
									struct node *x=head;
									while(x!=NULL) {
										int fage=x->age,fno[20],fcount=x->count,kite=strlen(x->oname);
										char fname[20],fnick[20];
										for(int i=0;i<=kite;i++)
											fname[i]=x->oname[i];
										fprintf(fptr,"\nName = %s\n",fname);
										if(x->alt==1) {
											int jerry=strlen(x->nick);
											for(int i=0;i<=jerry;i++)
												fnick[i]=x->nick[i];
											fprintf(fptr,"Nick name = %s\n",fnick);
										}
										fprintf(fptr,"Age = %d\n",fage);
										for(int i=0;i<=x->count;i++) {
											fno[i]=x->no[i];
											fprintf(fptr,"Telephone number [%d] = %d\n",i+1,fno[i]);
										}
										if(x->count==0)
											fprintf(fptr,"%s has 1 Telephone number\n",fname);
										else
											fprintf(fptr,"%s has %d Telephone numbers\n",fname,fcount+1);
										x=x->right;
									}
									if(Bhavik==1)
										fprintf(fptr,"\nThere is 1 contact available in the directory\n");
									else
										fprintf(fptr,"\nThere are %d contacts available in the directory\n",Bhavik);
									remove("FILE.c");
									rename("similar.c","FILE.c");
									printf("The file is edited\n");
									fclose(fptr);
								}
							}
							break;
							case 2: {
								int hello=0,dno,dno1,eye=0;
								printf("Enter the telephone number of the contact : ");
								scanf("%d",&dno);
								dno1=dno;
								while(dno1!=0) {
									dno1=dno1/10;
									eye++;
								}
								while(eye!=7) {
									printf("Enter a seven digit telephone number : ");
									scanf("%d",&dno);
									dno1=dno;
									eye=0;
									while(dno1!=0) {
										dno1=dno1/10;
										eye++;
									}
								}
								struct node *x=head;
								while(hello==0&&x!=NULL) {
									for(int i=0;i<=x->count;i++) {
										if(x->no[i]==dno) {
											while(1) {
												int s,dno;
												printf("Enter the telephone number to be added : ");
												while(1) {
													scanf("%d",&dno);
													int eye=0,dno2=dno,song=0;
													while(dno2!=0) {
														dno2=dno2/10;
														eye++;
													}
													while(eye!=7) {
														printf("Enter a seven digit telephone number : ");
														scanf("%d",&dno);
														eye=0,dno2=dno;
														while(dno2!=0) {
															dno2=dno2/10;
															eye++;
														}
													}
													struct node *b=head;
													while(song==0&&b!=NULL) {
														for(int i=0;i<=b->count;i++) {
															if(b->no[i]==dno) {
																printf("The telephone number %d already exists in %s's contact\nEnter another telephone number to be added : ",dno,b->oname);
																song++;
																break;
															}
														}
														b=b->right;
													}
													if(song==0)
														break;
												}
												hello++;
												x->count++;
												x->no[x->count]=dno;
												printf("The %d telephone number is added to %s's contact\n",x->no[x->count],x->oname);
												printf("Does %s have another telephone number to be added(1/0) : ",x->oname);
												scanf("%d",&s);
												while(s!=0&&s!=1) {
													printf("Enter 1 if true or 0 if false : ");
													scanf("%d",&s);
												}
												if(s==0)
													break;
											}
										}
									}
									x=x->right;
								}
								if(hello==0)
									printf("The %d telephone number does not exist in the directory\n",dno);
								else {
									FILE *fptr;
									fptr=fopen("similar.c","w");
									struct node *x=head;
									while(x!=NULL) {
										int fage=x->age,fno[20],fcount=x->count,kite=strlen(x->oname);
										char fname[20],fnick[20];
										for(int i=0;i<=kite;i++)
											fname[i]=x->oname[i];
										fprintf(fptr,"\nName = %s\n",fname);
										if(x->alt==1) {
											int jerry=strlen(x->nick);
											for(int i=0;i<=jerry;i++)
												fnick[i]=x->nick[i];
											fprintf(fptr,"Nick name = %s\n",fnick);
										}
										fprintf(fptr,"Age = %d\n",fage);
										for(int i=0;i<=x->count;i++) {
											fno[i]=x->no[i];
											fprintf(fptr,"Telephone number [%d] = %d\n",i+1,fno[i]);
										}
										if(x->count==0)
											fprintf(fptr,"%s has 1 Telephone number\n",fname);
										else
											fprintf(fptr,"%s has %d Telephone numbers\n",fname,fcount+1);
										x=x->right;
									}
									if(Bhavik==1)
										fprintf(fptr,"\nThere is 1 contact available in the directory\n");
									else
										fprintf(fptr,"\nThere are %d contacts available in the directory\n",Bhavik);
									remove("FILE.c");
									rename("similar.c","FILE.c");
									printf("The file is edited\n");
									fclose(fptr);
								}
							}
							break;
							default:
								printf("Please enter the correct choice 😭️\n");
						}
					}
					break;
					default:
						printf("Please enter the correct choice 😭️\n");
				}
			}
			break;
			case 2: {
				if(head==NULL) {
					printf("-The directory is empty-\n");
					break;
				}
				int x;
				printf("\n    ----1.Delete all the details of a person----\n    ----2.Delete a telephone number         ----\n  Enter your choice 😄️ : ");
				scanf("%d",&x);
				switch(x) {
					case 1: {
						int hello=0;
						char dname[20];
						printf("Enter the name of the person for whom all the details must be deleted : ");
						scanf("%s",dname);
						struct node *x=head;
						if(strcmp(head->oname,dname)==0) {
							if(Bhavik==1) {
								struct node *temp=head;
								free(temp);
								head=NULL;
								printf("All the details of %s have been deleted\n",dname);
								Bhavik--;
								FILE *fptr;
								fptr=fopen("FILE.c","w+");
								remove("FILE.c");
								break;
							}
							else {
								struct node *temp=head;
								head=head->right;
								temp->right=NULL;
								free(temp);
								Bhavik--;
								printf("All the details of %s have been deleted\n",dname);
								hello++;
							}
						}
						else if(Bhavik!=1)
							x=x->right;
						while(hello==0&&x->right!=NULL) {
							if(strcmp(x->oname,dname)==0) {
								struct node *temp=x;
								x->right->left=temp->left;
								x->left->right=temp->right;
								temp->left=temp->right=NULL;
								free(temp);
								Bhavik--;
								printf("All the details of %s have been deleted\n",dname);
								hello++;
								break;
							}
							x=x->right;
						}
						if(hello==0&&strcmp(x->oname,dname)==0) {
							struct node *temp;
							temp=x;
							x->left->right=NULL;
							temp->left=temp->right=NULL;
							free(temp);
							Bhavik--;
							hello++;
							printf("All the details of %s have been deleted\n",dname);
						}
						if(hello==0)
							printf("%s does not exist in the directory\n",dname);
						else if(Bhavik!=0) {
							FILE *fptr;
							fptr=fopen("similar.c","w");
							struct node *x=head;
							while(x!=NULL) {
								int fage=x->age,fno[20],fcount=x->count,kite=strlen(x->oname);
								char fname[20],fnick[20];
								for(int i=0;i<=kite;i++)
									fname[i]=x->oname[i];
								fprintf(fptr,"\nName = %s\n",fname);
								if(x->alt==1) {
									int jerry=strlen(x->nick);
									for(int i=0;i<=jerry;i++)
										fnick[i]=x->nick[i];
									fprintf(fptr,"Nick name = %s\n",fnick);
								}
								fprintf(fptr,"Age = %d\n",fage);
								for(int i=0;i<=x->count;i++) {
									fno[i]=x->no[i];
									fprintf(fptr,"Telephone number [%d] = %d\n",i+1,fno[i]);
								}
								if(x->count==0)
									fprintf(fptr,"%s has 1 Telephone number\n",fname);
								else
									fprintf(fptr,"%s has %d Telephone numbers\n",fname,fcount+1);
								x=x->right;
							}
							if(Bhavik==1)
								fprintf(fptr,"\nThere is 1 contact available in the directory\n");
							else
								fprintf(fptr,"\nThere are %d contacts available in the directory\n",Bhavik);
							remove("FILE.c");
							rename("similar.c","FILE.c");
							printf("The file is edited\n");
							fclose(fptr);
						}
					}
					break;
					case 2: {
						int hello=0,dno;
						printf("Enter the telephone number : ");
						scanf("%d",&dno);
						int dno1=dno,eye=0;
						while(dno1!=0) {
							dno1=dno1/10;
							eye++;
						}
						while(eye!=7) {
							printf("Enter a seven digit telephone number : ");
							scanf("%d",&dno);
							eye=0,dno1=dno;
							while(dno1!=0) {
								dno1=dno1/10;
								eye++;
							}
						}
						struct node *x=head;
						for(int i=0;i<=head->count;i++) {
							if(x->no[i]==dno) {
								if(head->count==0) {
									if(Bhavik==1) {
										struct node *temp=x;
										free(temp);
										head=NULL;
										Bhavik--;
										printf("The %d telephone number is deleted\nAll the details of %s have been deleted since it had only 1 telephone number\n",dno,x->oname);
										hello++;
										break;
									}
									else {
										struct node *temp=head;
										head=head->right;
										temp->right=NULL;
										free(temp);
										Bhavik--;
										printf("The %d telephone number is deleted\nAll the details of %s have been deleted since it had only 1 telephone number\n",dno,x->oname);
										hello++;
										break;
									}
								}
								else {
									for(int j=i;j<head->count;j++)
										head->no[j]=head->no[j+1];
									head->no[head->count]=0;
									head->count--;
									printf("The %d telephone number is deleted\n",dno);
									hello++;
									break;
								}
							}
						}
						if(hello==0&&Bhavik!=1)
							x=x->right;
						while(hello==0&&x->right!=NULL) {
							for(int i=0;i<=x->count;i++) {
								if(x->no[i]==dno) {
									if(x->count==0) {
										struct node *temp=x;
										x->right->left=temp->left;
										x->left->right=temp->right;
										temp->left=temp->right=NULL;
										free(temp);
										Bhavik--;
										printf("The %d telephone number is deleted\nAll the details of %s have been deleted since it had only 1 telephone number\n",dno,x->oname);
										hello++;
										break;
									}
									else {
										for(int j=i;j<x->count;j++)
											x->no[j]=x->no[j+1];
										x->no[x->count]=0;
										x->count--;
										printf("The %d telephone number is deleted\n",dno);
										hello++;
										break;
									}
								}
							}
							x=x->right;
						}
						if(hello==0) {
							for(int i=0;i<=x->count;i++) {
								if(x->no[i]==dno) {
									if(x->count==0) {
										struct node *temp;
										temp=x;
										x->left->right=NULL;
										temp->left=temp->right=NULL;
										free(temp);
										Bhavik--;
										printf("The %d telephone number is deleted\nAll the details of %s have been deleted since it had only 1 telephone number\n",dno,x->oname);
										hello++;
										break;
									}
									else {
										for(int j=i;j<x->count;j++)
											x->no[j]=x->no[j+1];
										x->no[x->count]=0;
										x->count--;
										printf("The %d telephone number is deleted\n",dno);
										hello++;
										break;
									}
								}
							}
						}
						if(hello==0)
							printf("The %d telephone number does not exist in the directory\n",dno);
						else if(Bhavik!=0) {
							FILE *fptr;
							fptr=fopen("similar.c","w");
							struct node *x=head;
							while(x!=NULL) {
								int fage=x->age,fno[20],fcount=x->count,kite=strlen(x->oname);
								char fname[20],fnick[20];
								for(int i=0;i<=kite;i++)
									fname[i]=x->oname[i];
								fprintf(fptr,"\nName = %s\n",fname);
								if(x->alt==1) {
									int jerry=strlen(x->nick);
									for(int i=0;i<=jerry;i++)
										fnick[i]=x->nick[i];
									fprintf(fptr,"Nick name = %s\n",fnick);
								}
								fprintf(fptr,"Age = %d\n",fage);
								for(int i=0;i<=x->count;i++) {
									fno[i]=x->no[i];
									fprintf(fptr,"Telephone number [%d] = %d\n",i+1,fno[i]);
								}
								if(x->count==0)
									fprintf(fptr,"%s has 1 Telephone number\n",fname);
								else
									fprintf(fptr,"%s has %d Telephone numbers\n",fname,fcount+1);
								x=x->right;
							}
							if(Bhavik==1)
								fprintf(fptr,"\nThere is 1 contact available in the directory\n");
							else
								fprintf(fptr,"\nThere are %d contacts available in the directory\n",Bhavik);
							remove("FILE.c");
							rename("similar.c","FILE.c");
							printf("The file is edited\n");
							fclose(fptr);
						}
					}
					break;
					default:
						printf("Please enter the correct choice 😭️\n");
				}
			}
			break;
			case 3: {
				if(head==NULL) {
					printf("-The directory is empty-\n");
					break;
				}
				int x;
				printf("\n    ----1.Display all the contacts  ----\n    ----2.Display a specific contact----\n  Enter your choice 😄️ : ");
				scanf("%d",&x);
				switch(x) {
					case 1: {
						struct node *x=head;
						while(x!=NULL) {
							printf("\nName = %s\n",x->oname);
							printf("Age = %d\n",x->age);
							if(x->alt==1)
								printf("Nick name = %s\n",x->nick);
							for(int i=0;i<=x->count;i++)
								printf("Telephone number [%d] = %d\n",i+1,x->no[i]);
							if(x->count==0)
								printf("%s has 1 Telephone number\n",x->oname);
							else
								printf("%s has %d Telephone numbers\n",x->oname,x->count+1);
							x=x->right;
						}
						if(Bhavik==1)
							printf("\nThere is 1 contact available in the directory\n");
						else
							printf("\nThere are %d contacts available in the directory\n",Bhavik);
					}
					break;
					case 2: {
						int y;
						printf("\n  --1.Enter the name of the person--\n  --2.Enter the telephone number  --\n Enter your choice 😄️ : ");
						scanf("%d",&y);
						switch(y) {
							case 1: {
								int hello=0;
								char dname[20];
								struct node *x=head;
								printf("Enter the name of the person to be displayed : ");
								scanf("%s",dname);
								while(x!=NULL) {
									if(strcmp(x->oname,dname)==0) {
										printf("\nName = %s\n",x->oname);
										if(x->alt==1)
											printf("Nick name = %s\n",x->nick);
										printf("Age = %d\n",x->age);
										for(int i=0;i<=x->count;i++)
											printf("Telephone number [%d] = %d\n",i+1,x->no[i]);
										if(x->count==0)
											printf("%s has 1 Telephone number\n",x->oname);
										else
											printf("%s has %d Telephone numbers\n",x->oname,x->count+1);
										hello++;
										break;
									}
									x=x->right;
								}
								if(hello==0)
									printf("%s does not exist in the directory\n",dname);
							}
							break;
							case 2: {
								int hello=0,dno;
								struct node *x=head;
								printf("Enter the telephone number of the contact to be displayed : ");
								scanf("%d",&dno);
								int eye=0,dno1=dno;
								while(dno1!=0) {
									dno1=dno1/10;
									eye++;
								}
								while(eye!=7) {
									printf("Enter a seven digit telephone number : ");
									scanf("%d",&dno);
									eye=0,dno1=dno;
									while(dno1!=0) {
										dno1=dno1/10;
										eye++;
									}
								}
								while(x!=NULL) {
									for(int j=0;j<=x->count;j++) {
										if(x->no[j]==dno) {
											printf("\nName = %s\n",x->oname);
											if(x->alt==1)
												printf("Nick name = %s\n",x->nick);
											printf("Age = %d\n",x->age);
											for(int i=0;i<=x->count;i++)
												printf("Telephone number [%d] = %d\n",i+1,x->no[i]);
											if(x->count==0)
												printf("%s has 1 Telephone number\n",x->oname);
											else
												printf("%s has %d Telephone numbers\n",x->oname,x->count+1);
											hello++;
											break;
										}
									}
									x=x->right;
								}
								if(hello==0)
									printf("The %d telephone number does not exist in the directory\n",dno);
							}
							break;
							default:
								printf("Please enter the correct choice 😭️\n");
						}
					}
					break;
					default:
						printf("Please enter the correct choice 😭️\n");
				}
			}
			break;
			case 4: 
				exit(0);
			break;
			default:
				printf("Please enter the correct choice 😭️\n");			
		}
	}
}
