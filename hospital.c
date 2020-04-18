#include "hospital.h"

patient_Record* patient[MAX_PATIENT]; // 회원정보데이터 (전역)
int _count = 0;

int p_is_available(){
    int i;
    for(i=0; i<MAX_PATIENT; i++){
        if(patient[i]==NULL) return 1;
    }
    return 0;
}

int p_first_available(){
    int i;
    for(i=0; i<MAX_PATIENT; i++){
        if(patient[i]==NULL) return i;
    }
    return -1;
}

int p_count(){
    return _count;
}

void p_create (char*p_n, int p_old , int p_height , int p_weight, int p_blood , int p_gender , char*p_disease , int p_room)
{
#ifdef DEBUG
    {
      printf("Debug : create\n");     
    }
#endif      
    int index = p_first_available();
    patient[index] = (patient_Record*)malloc(sizeof(patient_Record));
    patient_Record* p = patient[index];
    strcpy(p->name, p_n);  
    p->old = p_old;
    p->height = p_height;
    p->weight = p_weight;
    p->blood = p_blood;
    switch(p->blood)
    {
        case 1: 
        strcpy(p->BloodType,"O형");
        break;
        case 2: 
        strcpy(p->BloodType,"A형");
        break;
        case 3: 
        strcpy(p->BloodType,"B형");
        break;
        case 4: 
        strcpy(p->BloodType,"AB형");
        break;
        default:
        strcpy(p->BloodType,"Unknown");
    }
    p->gender = p_gender;
    switch(p->gender)
    {
        case 1: 
        strcpy(p->GenderType,"남성");
        break;
        case 2: 
        strcpy(p->GenderType,"여성");
        break;
        default:
        strcpy(p->GenderType,"Unknown");
    }
    strcpy(p->disease, p_disease); 
    p->room_num = p_room;
    _count++;
}

patient_Record* p_search_by_name(char* n){
#ifdef DEBUG
    printf("Debug : searched\n");
#endif    
    int i;
    for(i=0; i<MAX_PATIENT; i++){
        if(patient[i] && strcmp(patient[i]->name, n)==0) return patient[i];
    }
    return NULL;
}

void p_search_Old(int search_old)
{
#ifdef DEBUG
    {
      printf("Debug : search by old\n");    
    }
#endif 
    int i;
    int check = 0;
    for(i=0; i<_count; i++)
    {
        if(patient[i]->old == search_old)
        {
            printf("%s / %d세 \n",patient[i]->name , patient[i]-> old);
            check = check +1;
        }            
    }
    if (check == 0)
    {
        printf("NOT Found\n");
    }
    
}
void p_search_Blood(int search_blood)
{
#ifdef DEBUG
    {
      printf("Debug : search by blood\n");   
    }
#endif    
    int i;
    int check = 0;
    for(i=0; i<_count; i++)
    {
        if(patient[i]->blood == search_blood)
        {
            printf("%s / %s \n",patient[i]->name , patient[i]-> BloodType);
            check = check +1;
        }            
    }
    if (check == 0)
    {
        printf("NOT Found\n");
    }
}

void p_search_Gender(int search_gender)
{
#ifdef DEBUG
    {
      printf("Debug : search by gender\n");
    }
#endif 
    int i;
    int check = 0;
    for(i=0; i<_count; i++)
    {
        if(patient[i]->gender == search_gender)
        {
            printf("%s / %s \n",patient[i]->name , patient[i]-> GenderType);
            check = check +1;
        }            
    }
    if (check == 0)
    {
        printf("NOT Found\n");
    }
}
void p_search_Disease(char* search_disease)
{
    int i;
    int check = 0;
    for(i=0; i<_count; i++)
    {
        if(patient[i] && strstr(patient[i]->disease, search_disease)!=NULL)
        {
            printf("%s / %s \n",patient[i]->name , patient[i]-> disease);
            check = check +1;
        }            
    }
    if (check == 0)
    {
        printf("NOT Found\n");
    }
}
void p_search_Room(int search_room)
{
    int i;
    int check = 0;
    for(i=0; i<_count; i++)
    {
        if(patient[i]->room_num == search_room)
        {
            printf("%s / %d 호 \n",patient[i]->name , patient[i]-> room_num);
            check = check +1;
        }            
    }
    if (check == 0)
    {
        printf("NOT Found\n");
    }
    
}

void p_update_Disease(char* original_disease, char* change_disease)
{
#ifdef DEBUG
    {
      printf("Debug : Update\n");
    }
#endif 
    int i;
    int check = 0;
    printf("Before >> \n");
    for(i=0; i<_count; i++)
    {
        if(patient[i] && strcmp(patient[i]->disease, original_disease)==0)
        {
            printf("%s / %s / %d 호 \n",patient[i]->name , patient[i]-> disease , patient[i]-> room_num);
            strcpy(patient[i]->disease,change_disease);
            check = check +1;
        }            
    }
    if (check == 0)
    {
        printf("NOT Found\n");
    }
    else
    {
        printf("After >> \n");
        for(i=0; i<_count; i++)
        {
            if(patient[i] && strcmp(patient[i]->disease, change_disease)==0)
            {
                printf("%s / %s / %d 호 \n",patient[i]->name , patient[i]-> disease , patient[i]-> room_num);
            }            
        }
    }
}
void p_sort_list(int list_mode)
{
#ifdef DEBUG
    {
      printf("Debug : Sorted\n");
    }
#endif 
    patient_Record*temp;
    switch(list_mode)
     {
        case 1:
            for (int j = 0; j<_count; j++)
            {
                for (int i = 0; i<_count-1; i++)
                {
                    if(patient[i]->old > patient[i+1]->old)
                    {
                        temp = patient[i];
                        patient[i] = patient[i+1];
                        patient[i+1] = temp;
                    }
                }
            }
            printf("sorted");
            break;
        case 2:
            for (int j = 0; j<_count; j++)
            {
                for (int i = 0; i<_count-1; i++)
                {
                    if(patient[i]->room_num > patient[i+1]->room_num)
                    {
                        temp = patient[i];
                        patient[i] = patient[i+1];
                        patient[i+1] = temp;
                    }
                } 
            }
            printf("sorted");
            break;
        case 0: 
        default: 
            return;
     }

}

void p_update (patient_Record* p, int p_old , int p_height , int p_weight, int p_blood , int p_gender , char*p_disease , int p_room){
#ifdef DEBUG
    {
      printf("Debug : Update\n");
    }
#endif 
    p->old = p_old;
    p->height = p_height;
    p->weight = p_weight;
    p->blood = p_blood;
    p->gender = p_gender;
    strcpy(p->disease, p_disease); 
    p->room_num = p_room;
}

void p_delete(patient_Record* p){
#ifdef DEBUG
    {
      printf("Debug : Delete\n");
    }
#endif
    int i, index;
    for(i=0; i<MAX_PATIENT; i++)
        if(patient[i]==p) {
            index=i;
            break;
        }
    free(p);
    patient[index] = NULL;
    _count--;
}

char* p_to_string(patient_Record* p){
    static char str[999];
    sprintf(str, "나이 : %d 세 / 이름 : %s / 키 : %d Cm / 몸무게 : %d Kg / 혈액형 : %s / 성별 : %s / 병명 : %s / 호실 : %d 호", p->old, p->name, p->height, p->weight ,p->BloodType,p->GenderType,p->disease,p->room_num);
    return str;
}

void p_get_all(patient_Record* a[]){
    int i, c=0;
    for(i=0; i<MAX_PATIENT; i++){
        if(patient[i]){
            a[c]=patient[i];
            c++;
        }
    }
}
char* p_getname(patient_Record* p)   
{
    return p->name;
}
int p_getold(patient_Record* p)
{
    return p->old;
}
int p_getheight(patient_Record* p)
{
    return p->height;
}
int p_getweight(patient_Record* p)
{
    return p->weight;
}
char* p_getblood(patient_Record* p)
{   
    return p->BloodType;
}
char* p_getgender(patient_Record* p)
{
    
    return p->GenderType;
} 
char* p_getdisease(patient_Record* p)
{
    return p->disease;
}
int p_getroom(patient_Record* p)
{
    return p->room_num;
}
void p_save_file(char*p_file)
{
#ifdef DEBUG
    {
      printf("Debug : Saved\n");
    }
#endif
  FILE*myfile;
  myfile = fopen(p_file,"w");
  int size = p_count();
  patient_Record* records[MAX_PATIENT];
  p_get_all(records);
  for(int i=0; i<size; i++){
        patient_Record* p = records[i];
         fprintf(myfile, "나이 : %d 세 / 이름 : %s / 키 : %d Cm / 몸무게 : %d Kg / 혈액형 : %s / 성별 : %s / 병명 : %s / 호실 : %d 호\n", p->old, p->name, p->height, p->weight ,p->BloodType,p->GenderType,p->disease,p->room_num);
    }
  fclose(myfile);
}
void p_load_file(char* p_file)
{
#ifdef DEBUG
    {
      printf("Debug : Loaded\n");
    }
#endif
    char name[20];  int old;  int height; int weight;int blood; int gender;char disease[20]; int room_num;
    char sentence[100];
    int check_count = 0;
    int imformation_count = 0; // {나이 : 0 이름: 1 키 : 2 몸무게 : 3 혈액형 : 4 성별 ; 5 병명 : 6 호실 : 7}
    FILE*myfile;
    myfile = fopen(p_file,"r");
    if (myfile == NULL)
    {
        printf ("NOT Found file name : %s",p_file);
        return;
    }
   
    p_all_delete();
    for (int i =0; !feof(myfile); i++)
    {
        fscanf(myfile,"%s",sentence);
        if (check_count == 1)
        {
           // printf("%s ",sentence);
            check_count = 0;
            switch(imformation_count)
            {
                case 0 :
                    old = atoi(sentence); //나이
                    break;
                case 1 :
                    strcpy(name,sentence); //이름
                    break;
                case 2:
                    height = atoi(sentence); //키
                    break;
                case 3 :
                    weight = atoi(sentence); //몸무게
                    break;
                case 4 :
                    if (!(strcmp(sentence,"O형"))) //혈액형
                    {
                        blood = 1;
                    } 
                    else if (!(strcmp(sentence,"A형"))) 
                    {
                        blood = 2;
                    }  
                    else if (!(strcmp(sentence,"B형"))) 
                    {
                        blood = 3;
                    }  
                    else if (!(strcmp(sentence,"AB형"))) 
                    {
                        blood = 4;
                    }  
                    else
                    {
                       blood = 0; //Unknown
                    }
                    
                    break;
                case 5:
                    if (!(strcmp(sentence,"남성"))) // 성별
                    {
                        gender = 1;
                    }
                    else if (!(strcmp(sentence,"여성")))
                    {
                        gender = 2; 
                    }
                    else
                    {
                        gender = 0; //Unknown
                    }
                    break;
                case 6 :
                    strcpy(disease,sentence); //병명
                    break;
                case 7:
                    room_num = atoi(sentence); //호실
                    p_create (name, old, height , weight, blood , gender , disease , room_num);
                    imformation_count = -1;
                    break;
                default:
                    break;
            }
            imformation_count++;
        }
        if (!(strcmp(sentence,":")))
        {
            check_count++;
        }
    }
    fclose(myfile);
}

void p_all_delete(){

#ifdef DEBUG
    {
      printf("Debug : All_deleted\n");      
    }
#endif 
    int i;
    for(i=0; i<MAX_PATIENT; i++)
    {
        patient[i] = NULL;
    }
    _count = 0;;
}
