#include "hospital.h"

// 애플리케이션용 함수 원형
void create_record();
void read_record();
void update_record();
void delete_record();
void list_record();
void search_record();
void sort_record();
void change_disease();
void load_file();
void save_file();
void check_bmi();
//목적  create, read , update , delete , list의 기능을 만들자.
int count = 0; //카운트를 세서 MAX_MEMBERS를 넘는지 확인 전역변수로 만들어야지 create와 delete에서 모두 활용
int main(){
    int menu;
    while(1){
        printf("\n \t ------------------------------------------- Menu -------------------------------------------\n");
        printf ("\t 1.환자 정보 생성 \t 2.특정 환자 정보 읽기 \t 3.환자 정보 수정 \t 4.환자 정보 제거 \n");
        printf ("\t 5.환자 리스트 \t 6.특정 환자 찾기 \t 7.환자 정보 정렬 \t 8.BMI 검사 \n");
        printf ("\t 9.파일 읽기 \t 10. 파일 저장하기 \t 0.Quit > \n");
        scanf("%d", &menu);
        printf("\n");
        switch(menu){
            case 1: 
                create_record();
                break;
            case 2: 
                read_record();
                break;
            case 3: 
                update_record();
                break;
            case 4: 
                delete_record();
                break;
            case 5: 
                list_record();
                break;
            case 6: 
                search_record();
                break;
            case 7: 
                sort_record();
                break;
            case 8: 
                check_bmi();
                break;
            case 9: 
                load_file();
                break;
            case 10: 
                save_file();
                break;
            case 0: 
            default: 
                return 0;
        }
    }
    return 0;
}

void create_record(){
    char name[20];  
    int old, height, weight, blood, gender, room_num;
    char disease[1000];
    count++;
    printf("환자의 정보를 입력해주세요\n");
    printf("이름 > ");
    scanf("%s", name);
    if(p_search_by_name(name)) {
        printf("이미 존재하는 환자의 이름입니다.\n");
        count--;
        return;
    }
    printf("나이 > ");
    scanf("%d", &old);
    
    printf("키 > ");
    scanf("%d", &height);
    
    printf("몸무게 > ");
    scanf("%d", &weight);

    printf("혈액형 (1: O , 2: A , 3: B, 4: AB ) > ");
    scanf("%d", &blood);

    printf("성별 (1: 남성, 2: 여성) > ");
    scanf("%d", &gender);

    printf("앓고있는 질병 ex) (감기,당뇨,코로나...,메르스/ 공백(x)) > ");
    scanf("%s", disease);

    printf("방 번호 ");
    scanf("%d", &room_num);

    if (count <= MAX_PATIENT)
    {
        p_create (name, old, height , weight, blood , gender , disease , room_num);
    }
    else
    {
        printf("최대 %d명을 넘겼습니다. 변경 또는 삭제를 해주세요.",MAX_PATIENT);
        count--;
        return;
    }
 
}


void list_record(){
    printf("모든 정보를 가져왔습니다.\n");
    int size = p_count();
    patient_Record* records[MAX_PATIENT];
    p_get_all(records);
    for(int i=0; i<size; i++){
        patient_Record* p = records[i];
        printf("%d. %s\n", i+1, p_to_string(p));
    }
}
void read_record()
{   char name[20];
    printf("찾는 사람의 이름을 입력해주세요. > ");
    scanf("%s", name);
    if (!(p_search_by_name(name)))
       {    
           printf("존재하지 않는 이름입니다.");
           return; //찾을 이름이 없다면 리턴
       }
    printf("환자의 정보입니다.\n");
    printf("이름 : %s\n", p_getname(p_search_by_name(name)));
    printf("나이 : %d 세\n",p_getold(p_search_by_name(name)));
    printf("키 : %d Cm\n",p_getheight(p_search_by_name(name)));
    printf("몸무게 : %d Kg\n",p_getweight(p_search_by_name(name)));
    printf("혈액형 : %s\n",p_getblood(p_search_by_name(name)));
    printf("성별 : %s\n",p_getgender(p_search_by_name(name)));
    printf("앓고있는 질병 : %s\n",p_getdisease(p_search_by_name(name)));
    printf("방번호 : %d 호\n",p_getroom(p_search_by_name(name)));
}
void update_record()
{
   char name[20];  
    int old, height, weight, blood, gender, room_num;
    char disease[20];

    printf("수정 할 사람의 이름을 입력해주세요 > ");
    scanf("%s", name);
    if (!(p_search_by_name(name)))
       {    
           printf("존재하지 않는 이름입니다.");
           return; //업데이트할 이름이 없다면 리턴
       } 
    printf("나이 > ");
    scanf("%d", &old);
    
    printf("키 > ");
    scanf("%d", &height);
    
    printf("몸무게 > ");
    scanf("%d", &weight);

    printf("혈액형 (1: O , 2: A , 3: B, 4: AB ) > ");
    scanf("%d", &blood);

    printf("성별 (1: 남성, 2: 여성) > ");
    scanf("%d", &gender);

    printf("앓고있는 질병 > ");
    scanf("%s", disease);

    printf("방 번호 ");
    scanf("%d", &room_num);
  
    p_update(p_search_by_name(name), old, height , weight, blood , gender , disease , room_num);
    printf("업데이트 완료");
}
void delete_record()
{
    count--;
    char name[20];
    printf("삭제 할 사람의 이름을 검색해주세요 > ");
    scanf("%s", name);
    if (!(p_search_by_name(name)))
       {    
           printf("존재하지 않는 이름입니다.");
           count++;
           return; //삭제할 이름이 없다면 리턴
       } 
    p_delete(p_search_by_name(name));
    printf("삭제 완료");
}
void search_record()
{
    int old, blood, gender, room_num;
    char disease[20];
    int mode;
    printf("어떤정보로 찾으시겠습니까? : 1.나이 2.혈액형 3.성별 4.질병 5.방번호 0. Quit > ");
    scanf("%d",&mode);
     switch(mode)
     {
        case 1:
            printf("찾을 나이 > ");
            scanf("%d",&old);
            p_search_Old(old);
            break;
        case 2:
            printf("찾을 혈액형 (1: O , 2: A , 3: B, 4: AB ) > ");
            scanf("%d",&blood);
            p_search_Blood(blood);
            break;
        case 3:
            printf("찾을 성별 (1: 남성 , 2: 여성) >");
            scanf("%d",&gender);
            p_search_Gender(gender);
            break;
        case 4:
            printf("찾을 질병 > ");
            scanf("%s",disease);
            p_search_Disease(disease);
            break;
        case 5:
            printf("찾을 방번호 > ");
            scanf("%d",&room_num);
             p_search_Room(room_num);
            break;
        case 0: 
        default: 
            return;
     }
}
void sort_record()
{
    int mode = 0;
    printf("어떤 기준으로 정리되기를 원하십니까? > 1. 나이 2. 방 번호 0. Quit > ");
    scanf("%d",&mode);
    p_sort_list(mode);
}
void load_file()
{
    char file_name[20];
    int mode;
    printf ("모든 정보가 사라지고 파일의 정보를 읽어 옵니다. 1.진행 2. 보류 > ");
    scanf ("%d",&mode);
    if (mode == 1)
    {
        printf("읽을 파일의 이름을 입력해주세요 > ");
        scanf("%s", file_name);
        p_load_file(file_name);
    }
    else
    {
        return;
    }
}

void save_file()
{
    char file_name[20];
    printf("저장 할 파일의 이름을 입력해주세요 > ");
    scanf("%s", file_name);
    p_save_file(file_name);
    printf("저장되었습니다.");
}

void check_bmi()
{
    int size = p_count();
    patient_Record* records[MAX_PATIENT];
    p_get_all(records);
    float bmi; int cm; int kg;
    for(int i=0; i<size; i++){
        patient_Record* p = records[i];
        cm = p->height; kg = p->weight;
        bmi = kg / ((cm /100.0) * (cm/ 100.0));
        printf("%s / 키 : %d CM / 몸무게 : %d KG \n", p->name ,cm,kg);
        if (bmi >= 30)
        {
            printf ("BMI : %.1f / BMI 30 이상 : 비만 \n",bmi);
        }
        else if(bmi >= 25)
        {
            printf ("BMI : %.1f / BMI 30 미만  25이상 : 과체중 \n",bmi);
        }
        else if(bmi >= 18.5)
        {
            printf ("BMI : %.1f / 25미만 18.5이상 : 정상 \n",bmi);
        }
        else
        {
            printf ("BMI : %.1f/ BMI 18.5미만 : 저체중 \n",bmi);
        }
        //printf("%d. %s\n", i+1, p_to_string(p));
    }
}
