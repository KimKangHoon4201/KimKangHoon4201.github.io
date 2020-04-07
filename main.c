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
//목적  create, read , update , delete , list의 기능을 만들자.
int count = 0; //카운트를 세서 MAX_MEMBERS를 넘는지 확인 전역변수로 만들어야지 create와 delete에서 모두 활용
int main(){
    int menu;
    while(1){
        printf("\nMenu : 1.Create 2.Read 3.Update 4.Delete 5.List 6.Search 7.Sort 8.Change_disease 9.File Load, 10. File Save 0.Quit > ");
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
                change_disease();
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
    char disease[20];
    count++;
    printf("Enter a new member's info.\n");
    printf("Name > ");
    scanf("%s", name);
    if(p_search_by_name(name)) {
        printf("Duplicated name!\n");
        count--;
        return;
    }
    printf("Old > ");
    scanf("%d", &old);
    
    printf("Height > ");
    scanf("%d", &height);
    
    printf("Weight > ");
    scanf("%d", &weight);

    printf("blood (1: O , 2: A , 3: B, 4: AB ) > ");
    scanf("%d", &blood);

    printf("gender (1: 남성, 2: 여성) > ");
    scanf("%d", &gender);

    printf("Disease Name > ");
    scanf("%s", disease);

    printf("Room number ");
    scanf("%d", &room_num);

    if (count <= MAX_PATIENT)
    {
        p_create (name, old, height , weight, blood , gender , disease , room_num);
    }
    else
    {
        printf("최대 5명을 넘겼습니다. 변경 또는 삭제를 해주세요.");
        count--;
        return;
    }
 
}


void list_record(){
    printf("All records.\n");
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
    printf("You want read Name > ");
    scanf("%s", name);
    if (!(p_search_by_name(name)))
       {    
           printf("존재하지 않는 이름입니다.");
           return; //찾을 이름이 없다면 리턴
       }
    printf("Member info.\n");
    printf("Name : %s\n", p_getname(p_search_by_name(name)));
    printf("Old : %d 세\n",p_getold(p_search_by_name(name)));
    printf("Height : %d Cm\n",p_getheight(p_search_by_name(name)));
    printf("Weight : %d Kg\n",p_getweight(p_search_by_name(name)));
    printf("Blood : %s\n",p_getblood(p_search_by_name(name)));
    printf("Gender : %s\n",p_getgender(p_search_by_name(name)));
    printf("Disease Name : %s\n",p_getdisease(p_search_by_name(name)));
    printf("Room number : %d 호\n",p_getroom(p_search_by_name(name)));
}
void update_record()
{
   char name[20];  
    int old, height, weight, blood, gender, room_num;
    char disease[20];

    printf("You want update Name > ");
    scanf("%s", name);
    if (!(p_search_by_name(name)))
       {    
           printf("존재하지 않는 이름입니다.");
           return; //업데이트할 이름이 없다면 리턴
       } 
    printf("Old > ");
    scanf("%d", &old);
    
    printf("Height > ");
    scanf("%d", &height);
    
    printf("Weight > ");
    scanf("%d", &weight);

    printf("blood (1: O , 2: A , 3: B, 4: AB ) > ");
    scanf("%d", &blood);

    printf("gender (1: 남성, 2: 여성) > ");
    scanf("%d", &gender);

    printf("Disease Name > ");
    scanf("%s", disease);

    printf("Room number ");
    scanf("%d", &room_num);
  
    p_update(p_search_by_name(name), old, height , weight, blood , gender , disease , room_num);
    printf("업데이트 완료");
}
void delete_record()
{
    count--;
    char name[20];
    printf("You want delete Name > ");
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
    int old, height, weight, blood, gender, room_num;
    char disease[20];
    char name[20];
    int mode;
    printf("Choose One: 1. Old 2.Blood 3. Gender 4. Disease 5.Room_num  0. Quit > ");
    scanf("%d",&mode);
     switch(mode)
     {
        case 1:
            printf("Search Old > ");
            scanf("%d",&old);
            p_search_Old(old);
            break;
        case 2:
            printf("Search Blood (1: O , 2: A , 3: B, 4: AB ) > ");
            scanf("%d",&blood);
            p_search_Blood(blood);
            break;
        case 3:
            printf("Search Gender (1: 남성 , 2: 여성) >");
            scanf("%d",&gender);
            p_search_Gender(gender);
            break;
        case 4:
            printf("Search Disease > ");
            scanf("%s",disease);
            p_search_Disease(disease);
            break;
        case 5:
            printf("Search room_num > ");
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
    printf("What kind do you want? > 1. old 2. room 0. Quit > ");
    scanf("%d",&mode);
    p_sort_list(mode);
}
void change_disease()
{
    char disease[20];
    char new_disease[20];
    printf("Find Disease Name > ");
    scanf("%s", disease);
    printf("Change Disease  Name > ");
    scanf("%s", new_disease);
    p_update_Disease(disease, new_disease);
}
void load_file()
{
    char file_name[20];
    int mode;
    printf ("모든 정보가 사라지고 파일의 정보를 읽어 옵니다. 1.진행 2. 보류 > ");
    scanf ("%d",&mode);
    if (mode == 1)
    {
        printf("load file name > ");
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
    printf("save file name > ");
    scanf("%s", file_name);
    p_save_file(file_name);
    printf("Saved");
}
