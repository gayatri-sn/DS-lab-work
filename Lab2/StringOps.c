#include<stdio.h>
#include<string.h>
int string_length(char s1[])
{
   int i,count;
   for(i=0;s1[i]!='\0';i++){
    count++;
   }
   return(i);
}

int string_concat(char t[],char t1[])
{
   int i=0,j=0;
   while(t[i]!='\0'){
    i++;
   }
   while(t1[j]!='\0'){
    t[i]=t1[j];
    i++;
    j++;
   }
   t[i]='\0';
   return(t);
}

int string_comp(char t1[],char t2[]){
    int i,j;
    if(t1[i]==t2[i]&& t1[i]!='\0')
        return 0;
    else if(t1[i]>t2[i]&& t1[i]!='\0')
        return 1;
    else if(t1[i]<t2[i]&& t1[i]!='\0')
        return -1;

}

int string_insert(char r1[],char r2[],int p){
    char temp[100];
    int i=0,j=0,m=0,k=0;
    for(int i=p;r1[i]!='\0';i++){
        temp[k]=r1[i];
        k++;
    }
    temp[k]='\0';
    for(j=0;r2[j]!='\0';j++){
        r1[p]=r2[j];
        p++;
    }
    while(temp[m]!='\0'){
        r1[p]=temp[m];
        m++;
        p++;
    };
    r1[p]='\0';
    return(r1);
}

int  delete_substring(char str[],int start,int len,char result[]){
    int i = 0,j=0;
    while(i<start && str[i]!='\0'){
        result[j++] = str[i++];
    }
    i += len;
    while(str[i]!='\0'){
        result[j++] = str[i++];
    }
    result[j] = '\0';
}

int main()
{

    int key;
    char str1[100], str2[100];
    printf("Enter 1 for length of string, 2 for concatenation, 3 for comparison, 4 for inserting and 5 for deleting. \n ");
    scanf("%d",&key);

    if(key == 1){
        int len;
        printf("Enter string: \n");
        scanf("%s", str1);
        len = string_length(str1);
        printf("The length of the string is : %d",len);}

    else if(key == 2){
        printf("Enter first string: \n");
        scanf("%s", str1);
        printf("Enter second string: \n");
        scanf("%s", str2);
        printf("%s",string_concat(str1,str2));
    }

    else if(key == 3){
    printf("Enter first string:\n");
    scanf("%s",str1);
    printf("Enter second string:\n");
    scanf("%s",str2);
    int key = string_comp(str1,str2);
    if(key == 1)
        printf("String1 is greater than String2.");
    else if(key == -1)
        printf("String2 is greater than String1.");
    else if (key == 0){
        printf("String1 and String2 are equal.");}
    }

    else if(key == 4){
        int pos;
        printf("Enter string:");
        scanf("%s",str1);
        printf("Enter string to be inserted:");
        scanf("%s",str2);
        printf("Enter position to be inserted at:");
        scanf("%d",&pos);
        printf("After insertion: %s",string_insert(str1,str2,pos));}

    else if(key == 5){
        int pos,length;
        char result[100];
        printf("Enter string:");
        scanf("%s",str1);
        printf("Enter position: ");
        scanf("%d",&pos);
        printf("Enter length to be deleted:  ");
        scanf("%d",&length);
        delete_substring(str1,pos,length,result);
        printf("After deletion: %s",result);}
    return 0;

}
