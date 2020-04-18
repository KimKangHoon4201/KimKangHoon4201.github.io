#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENT 100      // 저장할 수 있는 회원 레코드 최대 갯수

// 회원 정보 레코드의 데이터 타입을 정의함
typedef struct st_patient{
    char name[20];  
    int old;  
    int height; 
    int weight;
    int blood; 
    int gender;
    char disease[20];
    int room_num;
    char BloodType[20];
    char GenderType[20];
} patient_Record;


// 라이브러리 함수 원형을 선언함
int p_is_available();       // 현재 추가할 수 있는 데이터 공간이 있는가?
int p_first_available();   // 추가할 수 있는 가장 빠른 포인터 배열의 인덱스 찾기
int p_count();
patient_Record* p_search_by_name(char* n);
void p_create (char*p_n, int p_old , int p_height , int p_weight, int p_blood , int p_gender , char*p_disease, int p_room);
void p_update (patient_Record* p, int p_old , int p_height , int p_weight, int p_blood , int p_gender , char*p_disease , int p_room);
void p_delete (patient_Record* p);
void p_get_all (patient_Record* a[]);
char* p_to_string(patient_Record* p); 
char* p_getname(patient_Record* p); 
int p_getold(patient_Record* p);
int p_getheight(patient_Record* p);
int p_getweight(patient_Record* p);  
char* p_getblood(patient_Record* p);
char* p_getgender(patient_Record* p);  
char* p_getdisease(patient_Record* p);  
int p_getroom(patient_Record* p);  

void p_search_Old(int search_old);
void p_search_Blood(int search_old);
void p_search_Gender(int search_old);
void p_search_Disease(char* search_old);
void p_search_Room(int search_room);
void p_update_Disease(char* original_disease, char* change_disease);
void p_sort_list(int list_mode);

void p_load_file(char* p_file);
void p_save_file(char* p_file);
void p_all_delete();
