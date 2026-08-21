#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_STUDENT 100
#define MAX_ROOM 50
#define MAX_NOTICE 20
#define MAX_COMPLAINT 100


void pauseScreen()
{
    printf("\n\nPress Enter to Continue...");
    getchar();
    getchar();
}

typedef struct
{
    uint32_t state[4];
    uint32_t count[2];
    unsigned char buffer[64];

} MD5_CTX;


#define F(x,y,z) ((x & y) | (~x & z))
#define G(x,y,z) ((x & z) | (y & ~z))
#define H(x,y,z) (x ^ y ^ z)
#define I(x,y,z) (y ^ (x | ~z))

#define ROTATE_LEFT(x,n) (((x) << (n)) | ((x) >> (32-(n))))


#define FF(a,b,c,d,x,s,ac)        \
{                                 \
    (a) += F((b),(c),(d)) + (x) + (uint32_t)(ac); \
    (a) = ROTATE_LEFT((a),(s));   \
    (a) += (b);                   \
}


#define GG(a,b,c,d,x,s,ac)        \
{                                 \
    (a) += G((b),(c),(d)) + (x) + (uint32_t)(ac); \
    (a) = ROTATE_LEFT((a),(s));   \
    (a) += (b);                   \
}


#define HH(a,b,c,d,x,s,ac)        \
{                                 \
    (a) += H((b),(c),(d)) + (x) + (uint32_t)(ac); \
    (a) = ROTATE_LEFT((a),(s));   \
    (a) += (b);                   \
}


#define II(a,b,c,d,x,s,ac)        \
{                                 \
    (a) += I((b),(c),(d)) + (x) + (uint32_t)(ac); \
    (a) = ROTATE_LEFT((a),(s));   \
    (a) += (b);                   \
}


void MD5Transform(uint32_t state[4],
                  const unsigned char block[64])
{
    uint32_t a,b,c,d,x[16];

    int i,j;

    for(i=0,j=0; i<16; i++,j+=4)
    {
        x[i] = ((uint32_t)block[j]) |
               ((uint32_t)block[j+1] << 8) |
               ((uint32_t)block[j+2] << 16) |
               ((uint32_t)block[j+3] << 24);
    }


    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];


    FF(a,b,c,d,x[0],7,0xd76aa478);
    FF(d,a,b,c,x[1],12,0xe8c7b756);
    FF(c,d,a,b,x[2],17,0x242070db);
    FF(b,c,d,a,x[3],22,0xc1bdceee);

    FF(a,b,c,d,x[4],7,0xf57c0faf);
    FF(d,a,b,c,x[5],12,0x4787c62a);
    FF(c,d,a,b,x[6],17,0xa8304613);
    FF(b,c,d,a,x[7],22,0xfd469501);

    FF(a,b,c,d,x[8],7,0x698098d8);
    FF(d,a,b,c,x[9],12,0x8b44f7af);
    FF(c,d,a,b,x[10],17,0xffff5bb1);
    FF(b,c,d,a,x[11],22,0x895cd7be);

    FF(a,b,c,d,x[12],7,0x6b901122);
    FF(d,a,b,c,x[13],12,0xfd987193);
    FF(c,d,a,b,x[14],17,0xa679438e);
    FF(b,c,d,a,x[15],22,0x49b40821);


    GG(a,b,c,d,x[1],5,0xf61e2562);
    GG(d,a,b,c,x[6],9,0xc040b340);
    GG(c,d,a,b,x[11],14,0x265e5a51);
    GG(b,c,d,a,x[0],20,0xe9b6c7aa);

    GG(a,b,c,d,x[5],5,0xd62f105d);
    GG(d,a,b,c,x[10],9,0x02441453);
    GG(c,d,a,b,x[15],14,0xd8a1e681);
    GG(b,c,d,a,x[4],20,0xe7d3fbc8);

    GG(a,b,c,d,x[9],5,0x21e1cde6);
    GG(d,a,b,c,x[14],9,0xc33707d6);
    GG(c,d,a,b,x[3],14,0xf4d50d87);
    GG(b,c,d,a,x[8],20,0x455a14ed);

    GG(a,b,c,d,x[13],5,0xa9e3e905);
    GG(d,a,b,c,x[2],9,0xfcefa3f8);
    GG(c,d,a,b,x[7],14,0x676f02d9);
    GG(b,c,d,a,x[12],20,0x8d2a4c8a);



    HH(a,b,c,d,x[5],4,0xfffa3942);
    HH(d,a,b,c,x[8],11,0x8771f681);
    HH(c,d,a,b,x[11],16,0x6d9d6122);
    HH(b,c,d,a,x[14],23,0xfde5380c);

    HH(a,b,c,d,x[1],4,0xa4beea44);
    HH(d,a,b,c,x[4],11,0x4bdecfa9);
    HH(c,d,a,b,x[7],16,0xf6bb4b60);
    HH(b,c,d,a,x[10],23,0xbebfbc70);

    HH(a,b,c,d,x[13],4,0x289b7ec6);
    HH(d,a,b,c,x[0],11,0xeaa127fa);
    HH(c,d,a,b,x[3],16,0xd4ef3085);
    HH(b,c,d,a,x[6],23,0x04881d05);

    HH(a,b,c,d,x[9],4,0xd9d4d039);
    HH(d,a,b,c,x[12],11,0xe6db99e5);
    HH(c,d,a,b,x[15],16,0x1fa27cf8);
    HH(b,c,d,a,x[2],23,0xc4ac5665);



    II(a,b,c,d,x[0],6,0xf4292244);
    II(d,a,b,c,x[7],10,0x432aff97);
    II(c,d,a,b,x[14],15,0xab9423a7);
    II(b,c,d,a,x[5],21,0xfc93a039);

    II(a,b,c,d,x[12],6,0x655b59c3);
    II(d,a,b,c,x[3],10,0x8f0ccc92);
    II(c,d,a,b,x[10],15,0xffeff47d);
    II(b,c,d,a,x[1],21,0x85845dd1);

    II(a,b,c,d,x[8],6,0x6fa87e4f);
    II(d,a,b,c,x[15],10,0xfe2ce6e0);
    II(c,d,a,b,x[6],15,0xa3014314);
    II(b,c,d,a,x[13],21,0x4e0811a1);

    II(a,b,c,d,x[4],6,0xf7537e82);
    II(d,a,b,c,x[11],10,0xbd3af235);
    II(c,d,a,b,x[2],15,0x2ad7d2bb);
    II(b,c,d,a,x[9],21,0xeb86d391);


    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}


void MD5Init(MD5_CTX *context)
{
    context->count[0] = 0;
    context->count[1] = 0;

    context->state[0] = 0x67452301;
    context->state[1] = 0xefcdab89;
    context->state[2] = 0x98badcfe;
    context->state[3] = 0x10325476;
}


void MD5Update(MD5_CTX *context,
               const unsigned char *input,
               unsigned int inputLen)
{
    unsigned int i;
    unsigned int index;
    unsigned int partLen;


    index = (unsigned int)((context->count[0] >> 3) & 0x3F);


    context->count[0] += ((uint32_t)inputLen << 3);


    if(context->count[0] < ((uint32_t)inputLen << 3))
    {
        context->count[1]++;
    }


    context->count[1] += ((uint32_t)inputLen >> 29);


    partLen = 64 - index;


    if(inputLen >= partLen)
    {
        memcpy(&context->buffer[index],
               input,
               partLen);


        MD5Transform(context->state,
                     context->buffer);


        for(i = partLen;
            i + 63 < inputLen;
            i += 64)
        {
            MD5Transform(context->state,
                         &input[i]);
        }


        index = 0;
    }
    else
    {
        i = 0;
    }


    memcpy(&context->buffer[index],
           &input[i],
           inputLen - i);
}


void MD5Final(unsigned char digest[16],
              MD5_CTX *context)
{
    unsigned char bits[8];

    unsigned char padding[64];

    unsigned int index;
    unsigned int padLen;

    int i;


    for(i=0; i<4; i++)
    {
        bits[i] =
            (unsigned char)
            (context->count[0] >> (8*i));

        bits[i+4] =
            (unsigned char)
            (context->count[1] >> (8*i));
    }


    index =
        (unsigned int)
        ((context->count[0] >> 3) & 0x3F);


    padLen =
        (index < 56)
        ? (56-index)
        : (120-index);


    memset(padding,0,sizeof(padding));

    padding[0] = 0x80;


    MD5Update(context,
              padding,
              padLen);


    MD5Update(context,
              bits,
              8);


    for(i=0; i<4; i++)
    {
        digest[i] =
            (unsigned char)
            (context->state[0] >> (8*i));

        digest[i+4] =
            (unsigned char)
            (context->state[1] >> (8*i));

        digest[i+8] =
            (unsigned char)
            (context->state[2] >> (8*i));

        digest[i+12] =
            (unsigned char)
            (context->state[3] >> (8*i));
    }
}

void md5Hash(const char *input,
             char *output)
{
    MD5_CTX context;

    unsigned char digest[16];

    int i;


    MD5Init(&context);


    MD5Update(&context,
              (const unsigned char *)input,
              strlen(input));


    MD5Final(digest,
             &context);


    for(i=0; i<16; i++)
    {
        sprintf(output + (i*2),
                "%02x",
                digest[i]);
    }


    output[32] = '\0';
}


typedef struct
{
    int id;
    char name[50];
    char password[33];
    char department[30];
    char phone[20];
    char gender[10];
    char parentEmail[100];
    char fatherName[50];
    char motherName[50];
    char guardianName[50];
    char guardianPhone[20];
    int roomNo;
    float feeDue;
} Student;

typedef struct
{
    int roomNo;
    int capacity;
    int occupied;
} Room;

typedef struct
{
    int studentId;
    char complaint[200];
} Complaint;

typedef struct
{
    char notice[200];
} Notice;

typedef struct
{
    int foodId;
    char foodName[50];
    float price;
} Food;
typedef struct
{
    int studentId;
    int foodId;
    int quantity;
    float totalBill;
    int paid;
} FoodOrder;

typedef struct
{
    int itemId;
    char itemName[50];
    char clue[200];
    char foundLocation[100];
    int claimed;
} LostFound;

typedef struct
{
    char itemName[50];
    int quantity;
} LaundryItem;


typedef struct
{
    int requestId;
    int studentId;

    LaundryItem items[20];
    int itemCount;

    char pickupDate[20];
    char status[20];

} Laundry;

Student students[MAX_STUDENT];
Room rooms[MAX_ROOM];
Complaint complaints[MAX_COMPLAINT];
Notice notices[MAX_NOTICE];
LostFound lostItems[100];
Food foods[100];
FoodOrder orders[500];
Laundry laundryRequests[100];

int studentCount = 0;
int roomCount = 0;
int complaintCount = 0;
int noticeCount = 0;
int lostItemCount = 0;
int orderCount=0;
int foodCount = 0;
int laundryCount = 0;


void saveStudents()
{
    FILE *fp = fopen("students.txt","w");

    if(fp == NULL)
        return;

    for(int i=0; i<studentCount; i++)
    {
        fprintf(fp,"%d %s %s %s %s %s %s %s %s %s %s %d %.2f\n",
                students[i].id,
                students[i].name,
                students[i].password,
                students[i].department,
                students[i].phone,
                students[i].gender,
                students[i].parentEmail,
                students[i].fatherName,
                students[i].motherName,
                students[i].guardianName,
                students[i].guardianPhone,
                students[i].roomNo,
                students[i].feeDue);
    }

    fclose(fp);
}

void loadStudents()
{
    FILE *fp=fopen("students.txt","r");

    if(fp==NULL)
        return;

    studentCount=0;

    while(fscanf(fp,"%d %s %s %s %s %s %s %s %s %s %s %d %f",
                 &students[studentCount].id,
                 students[studentCount].name,
                 students[studentCount].password,
                 students[studentCount].department,
                 students[studentCount].phone,
                 students[studentCount].gender,
                 students[studentCount].parentEmail,
                 students[studentCount].fatherName,
                 students[studentCount].motherName,
                 students[studentCount].guardianName,
                 students[studentCount].guardianPhone,
                 &students[studentCount].roomNo,
                 &students[studentCount].feeDue)==13)
    {
        studentCount++;
    }

    fclose(fp);
}


void saveRooms()
{
    FILE *fp=fopen("rooms.txt","w");

    if(fp==NULL)
        return;

    for(int i=0; i<roomCount; i++)
    {
        fprintf(fp,"%d %d %d\n",
                rooms[i].roomNo,
                rooms[i].capacity,
                rooms[i].occupied);
    }

    fclose(fp);
}

void loadRooms()
{
    FILE *fp=fopen("rooms.txt","r");

    if(fp==NULL)
        return;

    while(fscanf(fp,"%d %d %d",
                 &rooms[roomCount].roomNo,
                 &rooms[roomCount].capacity,
                 &rooms[roomCount].occupied)==3)
    {
        roomCount++;
    }

    fclose(fp);
}


void saveNotices()
{
    FILE *fp=fopen("notice.txt","w");

    if(fp==NULL)
        return;

    for(int i=0; i<noticeCount; i++)
    {
        fprintf(fp,"%s\n",notices[i].notice);
    }

    fclose(fp);
}

void loadNotices()
{
    FILE *fp=fopen("notice.txt","r");

    if(fp==NULL)
        return;

    while(fgets(notices[noticeCount].notice,200,fp))
    {
        notices[noticeCount].notice[strcspn(notices[noticeCount].notice,"\n")]=0;
        noticeCount++;
    }

    fclose(fp);
}


void saveComplaints()
{
    FILE *fp=fopen("complaint.txt","w");

    if(fp==NULL)
        return;

    for(int i=0; i<complaintCount; i++)
    {
        fprintf(fp,"%d %s\n",
                complaints[i].studentId,
                complaints[i].complaint);
    }

    fclose(fp);
}

void loadComplaints()
{
    FILE *fp=fopen("complaint.txt","r");

    if(fp==NULL)
        return;

    while(fscanf(fp,"%d %s",
                 &complaints[complaintCount].studentId,
                 complaints[complaintCount].complaint)==2)
    {
        complaintCount++;
    }

    fclose(fp);
}

int findStudent(int id)
{
    for(int i=0; i<studentCount; i++)
    {
        if(students[i].id==id)
            return i;
    }

    return -1;
}
void saveLostFound()
{
    FILE *fp = fopen("lost_found.txt","w");

    if(fp == NULL)
        return;

    for(int i=0; i<lostItemCount; i++)
    {
        fprintf(fp,"%d %s %s %s %d\n",
                lostItems[i].itemId,
                lostItems[i].itemName,
                lostItems[i].clue,
                lostItems[i].foundLocation,
                lostItems[i].claimed);
    }

    fclose(fp);
}

void saveFood()
{
    FILE *fp = fopen("food.txt","w");

    if(fp==NULL)
        return;

    for(int i=0; i<foodCount; i++)
    {
        fprintf(fp,"%d %s %.2f\n",
                foods[i].foodId,
                foods[i].foodName,
                foods[i].price);
    }

    fclose(fp);
}
void saveOrders()
{
    FILE *fp=fopen("orders.txt","w");

    if(fp==NULL)
        return;

    for(int i=0; i<orderCount; i++)
    {
        fprintf(fp,"%d %d %d %.2f %d\n",
                orders[i].studentId,
                orders[i].foodId,
                orders[i].quantity,
                orders[i].totalBill,
                orders[i].paid);
    }

    fclose(fp);
}
void loadLostFound()
{
    FILE *fp = fopen("lost_found.txt","r");

    if(fp == NULL)
        return;

    lostItemCount = 0;

    while(fscanf(fp,"%d %s %s %s %d",
                 &lostItems[lostItemCount].itemId,
                 lostItems[lostItemCount].itemName,
                 lostItems[lostItemCount].clue,
                 lostItems[lostItemCount].foundLocation,
                 &lostItems[lostItemCount].claimed)==5)
    {
        lostItemCount++;
    }

    fclose(fp);
}

void loadFood()
{
    FILE *fp = fopen("food.txt","r");

    if(fp==NULL)
        return;

    foodCount = 0;

    while(fscanf(fp,"%d %s %f",
                 &foods[foodCount].foodId,
                 foods[foodCount].foodName,
                 &foods[foodCount].price)==3)
    {
        foodCount++;
    }

    fclose(fp);
}

void loadOrders()
{
    FILE *fp=fopen("orders.txt","r");

    if(fp==NULL)
        return;

    orderCount=0;

    while(fscanf(fp,"%d %d %d %f %d",
                 &orders[orderCount].studentId,
                 &orders[orderCount].foodId,
                 &orders[orderCount].quantity,
                 &orders[orderCount].totalBill,
                 &orders[orderCount].paid)==5)
    {
        orderCount++;
    }

    fclose(fp);
}

int findRoom(int roomNo)
{
    for(int i=0; i<roomCount; i++)
    {
        if(rooms[i].roomNo==roomNo)
            return i;
    }

    return -1;
}
void saveLaundry()
{
    FILE *fp = fopen("laundry.txt", "w");

    if(fp == NULL)
        return;

    for(int i = 0; i < laundryCount; i++)
    {
        fprintf(fp, "%d %d %d %s %s ",
                laundryRequests[i].requestId,
                laundryRequests[i].studentId,
                laundryRequests[i].itemCount,
                laundryRequests[i].pickupDate,
                laundryRequests[i].status);

        for(int j = 0; j < laundryRequests[i].itemCount; j++)
        {
            fprintf(fp, "%s %d ",
                    laundryRequests[i].items[j].itemName,
                    laundryRequests[i].items[j].quantity);
        }

        fprintf(fp, "\n");
    }

    fclose(fp);
}
void loadLaundry()
{
    FILE *fp = fopen("laundry.txt", "r");

    if(fp == NULL)
        return;

    laundryCount = 0;

    while(laundryCount < 100)
    {
        Laundry *l = &laundryRequests[laundryCount];

        if(fscanf(fp, "%d %d %d %s %s",
                  &l->requestId,
                  &l->studentId,
                  &l->itemCount,
                  l->pickupDate,
                  l->status) != 5)
        {
            break;
        }

        for(int j = 0; j < l->itemCount; j++)
        {
            fscanf(fp, "%s %d",
                   l->items[j].itemName,
                   &l->items[j].quantity);
        }

        laundryCount++;
    }

    fclose(fp);
}


void registerStudent()
{
    Student s;
    char password[50];

    s.id = studentCount + 1;

    printf("\n===== Student Registration =====\n");

    printf("Enter Name : ");
    scanf("%s", s.name);

    printf("Enter Password : ");
    scanf("%s", password);

    md5Hash(password, s.password);

    printf("Enter Department : ");
    scanf("%s", s.department);

    printf("Enter Phone : ");
    scanf("%s", s.phone);

    printf("Enter Gender (Male/Female): ");
    scanf("%s", s.gender);

    printf("Enter Parent Email: ");
    scanf("%s", s.parentEmail);

    printf("Enter Father's Name : ");
    scanf("%s", s.fatherName);

    printf("Enter Mother's Name : ");
    scanf("%s", s.motherName);

    printf("Enter Local Guardian Name : ");
    scanf("%s", s.guardianName);

    printf("Enter Local Guardian Phone : ");
    scanf("%s", s.guardianPhone);

    s.roomNo = 0;
    s.feeDue = 0;

    students[studentCount] = s;
    studentCount++;

    saveStudents();

    printf("\nRegistration Successful!\n");
    printf("Your Student ID : %d\n", s.id);
}
int studentLogin()
{
    int id;
    char password[50];
    char hashedPassword[33];

    printf("\n===== Student Login =====\n");

    printf("Student ID : ");
    scanf("%d",&id);

    printf("Password : ");
    scanf("%s",password);

    md5Hash(password, hashedPassword);

    for(int i = 0; i < studentCount; i++)
    {
        if(students[i].id == id &&
           strcmp(students[i].password, hashedPassword) == 0)
        {
            printf("\nLogin Successful!\n");
            return i;
        }
    }

    printf("\nInvalid Student ID or Password!\n");

    return -1;
}

int adminLogin()
{
    char username[20];
    char password[20];

    printf("\n===== Admin Login =====\n");

    printf("Username : ");
    scanf("%s",username);

    printf("Password : ");
    scanf("%s",password);

    if(strcmp(username,"admin")==0 &&
            strcmp(password,"1234")==0)
    {
        printf("\nAdmin Login Successful!\n");
        return 1;
    }

    printf("\nInvalid Username or Password!\n");

    return 0;
}

void viewProfile(int index)
{
    printf("\n========== PROFILE ==========\n");

    printf("Student ID : %d\n",students[index].id);
    printf("Name       : %s\n",students[index].name);
    printf("Department : %s\n",students[index].department);
    printf("Phone      : %s\n",students[index].phone);
    printf("Father Name        : %s\n", students[index].fatherName);
    printf("Mother Name        : %s\n", students[index].motherName);
    printf("Guardian Name      : %s\n", students[index].guardianName);
    printf("Guardian Phone     : %s\n", students[index].guardianPhone);
    printf("Parent Email       : %s\n", students[index].parentEmail);
    printf("Room No    : %d\n",students[index].roomNo);
    printf("Fee Due    : %.2f\n",students[index].feeDue);
}

void viewFee(int index)
{
    printf("\nCurrent Due Fee : %.2f\n",
           students[index].feeDue);
}

void viewStudents()
{
    if(studentCount==0)
    {
        printf("\nNo Student Found.\n");
        return;
    }

    printf("\n=========== STUDENT LIST ===========\n");

    for(int i=0; i<studentCount; i++)
    {
        printf("\nID         : %d\n",students[i].id);
        printf("Name       : %s\n",students[i].name);
        printf("Department : %s\n",students[i].department);
        printf("Phone      : %s\n",students[i].phone);
        printf("Father Name    : %s\n", students[i].fatherName);
        printf("Mother Name    : %s\n", students[i].motherName);
        printf("Guardian Name  : %s\n", students[i].guardianName);
        printf("Guardian Phone : %s\n", students[i].guardianPhone);
        printf("Parent Email   : %s\n", students[i].parentEmail);
        printf("Room No    : %d\n",students[i].roomNo);
        printf("Fee Due    : %.2f\n",students[i].feeDue);

        printf("-----------------------------------\n");
    }
}


void addRoom()
{
    Room r;

    printf("\n========== ADD ROOM ==========\n");

    printf("Enter Room Number : ");
    scanf("%d",&r.roomNo);

    if(findRoom(r.roomNo)!=-1)
    {
        printf("\nRoom Already Exists!\n");
        return;
    }

    printf("Enter Capacity : ");
    scanf("%d",&r.capacity);

    r.occupied=0;

    rooms[roomCount]=r;
    roomCount++;

    saveRooms();

    printf("\nRoom Added Successfully.\n");
}

void viewRooms()
{
    if(roomCount==0)
    {
        printf("\nNo Room Available.\n");
        return;
    }

    printf("\n=========== ROOM LIST ===========\n");

    for(int i=0; i<roomCount; i++)
    {
        printf("\nRoom Number : %d\n",rooms[i].roomNo);
        printf("Capacity    : %d\n",rooms[i].capacity);
        printf("Occupied    : %d\n",rooms[i].occupied);
        printf("Available   : %d\n",
               rooms[i].capacity-rooms[i].occupied);

        printf("-------------------------------\n");
    }
}

void allocateRoom()
{
    int studentId;
    int roomNo;

    printf("\n========== ALLOCATE ROOM ==========\n");

    printf("Enter Student ID : ");
    scanf("%d",&studentId);

    int s=findStudent(studentId);

    if(s==-1)
    {
        printf("\nStudent Not Found.\n");
        return;
    }

    if(students[s].roomNo!=0)
    {
        printf("\nStudent Already Has A Room.\n");
        return;
    }

    printf("Enter Room Number : ");
    scanf("%d",&roomNo);

    int r=findRoom(roomNo);

    if(r==-1)
    {
        printf("\nRoom Not Found.\n");
        return;
    }

    if(rooms[r].occupied>=rooms[r].capacity)
    {
        printf("\nRoom Is Full.\n");
        return;
    }

    students[s].roomNo=roomNo;
    rooms[r].occupied++;

    saveStudents();
    saveRooms();

    printf("\nRoom Allocated Successfully.\n");
}

void removeRoom()
{
    int roomNo;

    printf("\nEnter Room Number : ");
    scanf("%d",&roomNo);

    int r=findRoom(roomNo);

    if(r==-1)
    {
        printf("\nRoom Not Found.\n");
        return;
    }

    if(rooms[r].occupied>0)
    {
        printf("\nStudents Are Living In This Room.\n");
        return;
    }

    for(int i=r; i<roomCount-1; i++)
    {
        rooms[i]=rooms[i+1];
    }

    roomCount--;

    saveRooms();

    printf("\nRoom Deleted Successfully.\n");
}

void vacateRoom()
{
    int studentId;

    printf("\nEnter Student ID : ");
    scanf("%d",&studentId);

    int s=findStudent(studentId);

    if(s==-1)
    {
        printf("\nStudent Not Found.\n");
        return;
    }

    if(students[s].roomNo==0)
    {
        printf("\nStudent Has No Room.\n");
        return;
    }

    int r=findRoom(students[s].roomNo);

    if(r!=-1)
    {
        rooms[r].occupied--;
    }

    students[s].roomNo=0;

    saveStudents();
    saveRooms();

    printf("\nRoom Vacated Successfully.\n");
}

void payFee(int index)
{
    float amount;

    printf("\nCurrent Due : %.2f\n",students[index].feeDue);

    printf("Enter Amount : ");
    scanf("%f",&amount);

    if(amount<=0)
    {
        printf("\nInvalid Amount.\n");
        return;
    }

    if(amount>students[index].feeDue)
    {
        printf("\nAmount is greater than Due.\n");
        return;
    }

    students[index].feeDue -= amount;

    saveStudents();

    FILE *fp=fopen("payment.txt","a");

    if(fp!=NULL)
    {
        fprintf(fp,"%d %.2f\n",students[index].id,amount);
        fclose(fp);
    }

    printf("\nPayment Successful.\n");
}

void addComplaint()
{
    FILE *fp;

    char complaint[200];

    getchar();

    printf("\nEnter Complaint : ");
    fgets(complaint,sizeof(complaint),stdin);

    fp=fopen("student_complaints.txt","a");

    if(fp==NULL)
    {
        printf("File Error.\n");
        return;
    }

    fputs(complaint,fp);

    fclose(fp);

    printf("\nComplaint Submitted Successfully.\n");
}

void viewComplaints()
{
    FILE *fp;

    char line[200];

    fp=fopen("student_complaints.txt","r");

    if(fp==NULL)
    {
        printf("\nNo Complaint Found.\n");
        return;
    }

    printf("\n===== STUDENT COMPLAINT =====\n\n");

    while(fgets(line,sizeof(line),fp))
    {
        printf("%s",line);
    }

    fclose(fp);
}

void addNotice()
{
    Notice n;

    getchar();

    printf("\nEnter Notice : ");

    fgets(n.notice,200,stdin);

    n.notice[strcspn(n.notice,"\n")]=0;

    notices[noticeCount]=n;

    noticeCount++;

    saveNotices();

    printf("\nNotice Added Successfully.\n");
}

void viewNotice()
{
    if(noticeCount==0)
    {
        printf("\nNo Notice Available.\n");
        return;
    }

    printf("\n========== NOTICE BOARD ==========\n");

    for(int i=0; i<noticeCount; i++)
    {
        printf("%d. %s\n",
               i+1,
               notices[i].notice);
    }
}

void deleteNotice()
{
    int num;

    printf("\nEnter Notice Number : ");
    scanf("%d",&num);

    if(num<1 || num>noticeCount)
    {
        printf("\nInvalid Notice Number.\n");
        return;
    }

    for(int i=num-1; i<noticeCount-1; i++)
    {
        notices[i]=notices[i+1];
    }

    noticeCount--;

    saveNotices();

    printf("\nNotice Deleted Successfully.\n");
}

void leaveRequest()
{
    int id;
    char reason[200];

    printf("\n========== LEAVE REQUEST ==========\n");

    printf("Enter Student ID : ");
    scanf("%d",&id);

    getchar();

    printf("Enter Reason : ");
    fgets(reason,200,stdin);

    reason[strcspn(reason,"\n")] = 0;

    FILE *fp = fopen("leave.txt","a");

    if(fp==NULL)
    {
        printf("File Error!\n");
        return;
    }

    fprintf(fp,"%d %s\n",id,reason);

    fclose(fp);

    printf("\nLeave Request Submitted Successfully.\n");
}

void visitorRequest()
{
    int id;
    char visitor[100];

    printf("\n========== VISITOR REQUEST ==========\n");

    printf("Enter Student ID : ");
    scanf("%d",&id);

    getchar();

    printf("Visitor Name : ");
    fgets(visitor,100,stdin);

    visitor[strcspn(visitor,"\n")] = 0;

    FILE *fp = fopen("visitor.txt","a");

    if(fp==NULL)
    {
        printf("File Error!\n");
        return;
    }

    fprintf(fp,"%d %s\n",id,visitor);

    fclose(fp);

    printf("\nVisitor Request Submitted Successfully.\n");
}

char messMenu[7][100];

void markAttendance()
{
    int id;
    char status;

    printf("\n========== ATTENDANCE ==========\n");

    printf("Student ID : ");
    scanf("%d",&id);

    printf("P = Present | A = Absent : ");
    scanf(" %c",&status);

    FILE *fp = fopen("attendance.txt","a");

    if(fp==NULL)
        return;

    fprintf(fp,"%d %c\n",id,status);

    fclose(fp);

    printf("\nAttendance Saved Successfully.\n");
}




void viewAttendance()
{
    FILE *fp = fopen("attendance.txt","r");

    int id;
    char status;

    if(fp==NULL)
    {
        printf("\nNo Attendance Record Found.\n");
        return;
    }

    printf("\n========== ATTENDANCE LIST ==========\n");

    while(fscanf(fp,"%d %c",&id,&status)==2)
    {
        printf("Student ID : %d   Status : %c\n",id,status);
    }

    fclose(fp);
}
void checkIn(Student s)
{
    int hour;
    int minute;

    printf("\n========== CHECK IN ==========\n");

    printf("Enter Current Hour (24 Format): ");
    scanf("%d", &hour);

    printf("Enter Current Minute : ");
    scanf("%d", &minute);

    if(hour < 0 || hour > 23 || minute < 0 || minute > 59)
    {
        printf("\nInvalid Time!\n");
        return;
    }

    FILE *fp = fopen("attendance.txt", "a");

    if(fp == NULL)
    {
        printf("\nError opening attendance file!\n");
        return;
    }

    fprintf(fp,
            "%d %s CHECK-IN %02d:%02d\n",
            s.id,
            s.name,
            hour,
            minute);

    fclose(fp);

    int late = 0;

    /* Male last entry time = 10:00 PM */
   if(strcmp(s.gender,"Male") == 0 ||
   strcmp(s.gender,"male") == 0)
{
    if(hour > 22 || (hour == 22 && minute > 0))
    {
        late = 1;
    }
}

    /* Female last entry time = 7:00 PM */
   else if(strcmp(s.gender,"Female") == 0 ||
        strcmp(s.gender,"female") == 0)
{
    if(hour > 19 || (hour == 19 && minute > 0))
    {
        late = 1;
    }
}
    if(late == 1)
    {
        FILE *cp = fopen("Late_Entry.txt", "a");

        if(cp == NULL)
        {
            printf("\nError opening Late_Entry.txt!\n");
            return;
        }

        fprintf(cp,
                "Student ID : %d\n"
                "Student : %s\n"
                "Gender : %s\n"
                "Parent Email : %s\n"
                "Late Entry : %02d:%02d\n"
                "Status : Late Entry Complaint\n"
                "----------------------------------------\n",
                s.id,
                s.name,
                s.gender,
                s.parentEmail,
                hour,
                minute);

        fclose(cp);

        printf("\n*** LATE ENTRY DETECTED! ***\n");
        printf("Late Entry Complaint Sent Successfully.\n");
        printf("Parent Email : %s\n", s.parentEmail);
    }
    else
    {
        printf("\nCheck In Successful.\n");
        printf("Entry Time : %02d:%02d\n", hour, minute);
    }
}
void checkOut(Student s)
{
    int hour;

    printf("Enter Current Hour (24 Format): ");
    scanf("%d",&hour);

    FILE *fp=fopen("attendance.txt","a");

    fprintf(fp,"%d CHECK-OUT %d:00\n",s.id,hour);

    fclose(fp);

    printf("\nCheck Out Successful.\n");

}

void savePaymentHistory(int id, float amount)
{
    FILE *fp = fopen("payment.txt","a");

    if(fp==NULL)
        return;

    fprintf(fp,"%d %.2f\n", id, amount);

    fclose(fp);
}

void paymentHistory(int index)
{
    FILE *fp=fopen("payment.txt","r");

    int id;
    float amount;
    int found=0;

    if(fp==NULL)
    {
        printf("\nNo Payment History.\n");
        return;
    }

    printf("\n===== PAYMENT HISTORY =====\n");

    while(fscanf(fp,"%d %f",&id,&amount)==2)
    {
        if(id==students[index].id)
        {
            printf("Paid : %.2f\n",amount);
            found=1;
        }
    }

    fclose(fp);

    if(found==0)
        printf("No Payment Found.\n");
}

void canteenMenu(int index)
{
    int choice;

    while(1)
    {
        printf("\n========== CANTEEN MANAGEMENT ==========\n");

        printf("1. View Food Menu\n");
        printf("2. Order Food\n");
        printf("3. Pay Food Bill\n");
        printf("0. Back\n");

        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            viewFood();
            break;

        case 2:
            orderFood(index);
            break;

        case 3:
            payFoodBill(index);
            break;

        case 0:
            return;

        default:
            printf("\nInvalid Choice.\n");
        }
    }
}

void orderFood(int index)
{
    int id,qty;

    printf("Enter Food ID : ");
    scanf("%d",&id);

    printf("Quantity : ");
    scanf("%d",&qty);

    for(int i=0; i<foodCount; i++)
    {
        if(foods[i].foodId==id)
        {
            orders[orderCount].studentId=students[index].id;
            orders[orderCount].foodId=id;
            orders[orderCount].quantity=qty;
            orders[orderCount].totalBill=foods[i].price*qty;
            orders[orderCount].paid=0;

            orderCount++;

            saveOrders();

            printf("\nOrder Successful.\n");
            printf("Total Bill : %.2f\n",
                   foods[i].price*qty);

            return;
        }
    }

    printf("\nFood Not Found.\n");
}

void payFoodBill(int index)
{
    int found=0;

    for(int i=0; i<orderCount; i++)
    {
        if(orders[i].studentId==students[index].id &&
                orders[i].paid==0)
        {
            printf("\nTotal Bill : %.2f\n",
                   orders[i].totalBill);

            printf("Payment Successful.\n");

            orders[i].paid=1;

            saveOrders();

            found=1;
        }
    }

    if(found==0)
    {
        printf("\nNo Pending Bill.\n");
    }
}

void applyLaundry(int studentId)
{
    int index;
    int itemCount;

    printf("\n========== APPLY FOR LAUNDRY ==========\n");

    index = findStudent(studentId);

    if(index == -1)
    {
        printf("\nStudent not found!\n");
        return;
    }

    printf("\nStudent Name : %s\n", students[index].name);
    printf("Gender       : %s\n", students[index].gender);

    if(laundryCount >= 100)
    {
        printf("\nLaundry request limit reached.\n");
        return;
    }

    Laundry *l = &laundryRequests[laundryCount];

    l->requestId = laundryCount + 1;
    l->studentId = studentId;

    printf("\nHow many different items do you want to give? ");
    scanf("%d", &itemCount);

    if(itemCount <= 0 || itemCount > 20)
    {
        printf("\nYou can enter 1 to 20 different items.\n");
        return;
    }

    l->itemCount = itemCount;

    for(int i = 0; i < itemCount; i++)
    {
        printf("\nItem %d Name     : ", i + 1);
        scanf("%s", l->items[i].itemName);

        printf("Item %d Quantity : ", i + 1);
        scanf("%d", &l->items[i].quantity);

        if(l->items[i].quantity <= 0)
        {
            printf("\nInvalid quantity!\n");
            return;
        }
    }

    printf("\nPickup Date (DD-MM-YYYY): ");
    scanf("%s", l->pickupDate);

    strcpy(l->status, "Pending");

    laundryCount++;

    saveLaundry();

    printf("\n====================================\n");
    printf("Laundry Request Submitted Successfully!\n");
    printf("Request ID : %d\n", l->requestId);
    printf("Status     : Pending\n");
    printf("====================================\n");
}
void viewLaundryStatus(int studentId)
{
    int found = 0;

    printf("\n========== MY LAUNDRY REQUESTS ==========\n");

    for(int i = 0; i < laundryCount; i++)
    {
        if(laundryRequests[i].studentId == studentId)
        {
            found = 1;

            printf("\nRequest ID : %d\n",
                   laundryRequests[i].requestId);

            printf("Student ID : %d\n",
                   laundryRequests[i].studentId);

            printf("Items:\n");

            for(int j = 0;
                    j < laundryRequests[i].itemCount;
                    j++)
            {
                printf("  %s - %d\n",
                       laundryRequests[i].items[j].itemName,
                       laundryRequests[i].items[j].quantity);
            }

            printf("Pickup Date : %s\n",
                   laundryRequests[i].pickupDate);

            printf("Status      : %s\n",
                   laundryRequests[i].status);

            printf("----------------------------------------\n");
        }
    }

    if(found == 0)
    {
        printf("\nNo Laundry Request Found.\n");
    }
}
void laundryMenu(int studentId)
{
    int choice;

    while(1)
    {
        system("cls");

        printf("\n=====================================\n");
        printf("          LAUNDRY SYSTEM\n");
        printf("=====================================\n");

        printf("1. Apply for Laundry\n");
        printf("2. View Laundry Status\n");
        printf("0. Back\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            applyLaundry(studentId);
            pauseScreen();
            break;

        case 2:
            viewLaundryStatus(studentId);
            pauseScreen();
            break;

        case 0:
            return;

        default:
            printf("\nInvalid Choice.\n");
            pauseScreen();
        }
    }
}
void studentMenu(int index)
{
    int choice;

    while(1)
    {
        system("cls");
        printf("\n========== STUDENT MENU ==========\n");
        printf("1. View Profile\n");
        printf("2. View Fee\n");
        printf("3. Pay Fee\n");
        printf("4. Payment History\n");
        printf("5. View Notice\n");
        printf("6. Add Complaint\n");
        printf("7. Leave Request\n");
        printf("8. Visitor Request\n");
        printf("9. View Attendance\n");
        printf("10. Check In\n");
        printf("11. Check Out\n");
        printf("12. Canteen\n");
        printf("13. Lost & Found\n");
        printf("14. Laundry System\n");
        printf("0. Logout\n");


        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            viewProfile(index);
            pauseScreen();
            break;

        case 2:
            viewFee(index);
            pauseScreen();
            break;

        case 3:
            payFee(index);
            pauseScreen();
            break;

        case 4:
            paymentHistory(index);
            pauseScreen();
            break;

        case 5:
            viewNotice();
            pauseScreen();
            break;

        case 6:
            addComplaint();
            pauseScreen();
            break;

        case 7:
            leaveRequest();
            pauseScreen();
            break;

        case 8:
            visitorRequest();
            pauseScreen();
            break;

        case 9:
            viewAttendance();
            pauseScreen();
            break;

        case 10:
            checkIn(students[index]);
            pauseScreen();
            break;

        case 11:
            checkOut(students[index]);
            pauseScreen();
            break;

        case 12:
            canteenMenu(index);
            pauseScreen();
            break;
        case 13:

            system("cls");

            printf("\n========== LOST & FOUND ==========\n");
            printf("1. View Found Items\n");
            printf("2. Search Lost Item\n");
            printf("3. Claim Item\n");
            printf("0. Back\n");

            printf("\nEnter Choice : ");

            int lfChoice;
            scanf("%d",&lfChoice);

            switch(lfChoice)
            {
            case 1:
                system("cls");
                viewFoundItems();
                pauseScreen();
                break;

            case 2:
                system("cls");
                searchLostItem();
                pauseScreen();
                break;

            case 3:
                system("cls");
                claimLostItem();
                pauseScreen();
                break;

            case 0:
                break;

            default:
                printf("\nInvalid Choice.\n");
                pauseScreen();
            }

            break;
        case 14:
            laundryMenu(students[index].id);
            pauseScreen();
            break;

        case 0:
            return;

        default:
            printf("\nInvalid Choice.\n");
        }
    }
}
void searchStudent()
{
    int id;

    printf("\nEnter Student ID : ");
    scanf("%d",&id);

    int s = findStudent(id);

    if(s == -1)
    {
        printf("\nStudent Not Found.\n");
        return;
    }

    printf("\nStudent ID : %d\n", students[s].id);
    printf("Name       : %s\n", students[s].name);
    printf("Department : %s\n", students[s].department);
    printf("Phone      : %s\n", students[s].phone);
    printf("Room No    : %d\n", students[s].roomNo);
    printf("Fee Due    : %.2f\n", students[s].feeDue);
}
void viewLeaveRequest()
{
    FILE *fp = fopen("leave.txt","r");

    char line[250];

    if(fp == NULL)
    {
        printf("\nNo Leave Request Found.\n");
        return;
    }

    printf("\n========== LEAVE REQUEST ==========\n");

    while(fgets(line,250,fp))
    {
        printf("%s",line);
    }

    fclose(fp);
}
void viewVisitorRequest()
{
    FILE *fp = fopen("visitor.txt","r");

    char line[250];

    if(fp == NULL)
    {
        printf("\nNo Visitor Request Found.\n");
        return;
    }

    printf("\n========== VISITOR REQUEST ==========\n");

    while(fgets(line,250,fp))
    {
        printf("%s",line);
    }

    fclose(fp);
}
void studentReport()
{
    printf("\n========== REPORT ==========\n");

    printf("Total Students   : %d\n", studentCount);
    printf("Total Rooms      : %d\n", roomCount);
    printf("Total Complaints : %d\n", complaintCount);
    printf("Total Notices    : %d\n", noticeCount);
}

void UpdateFee()
{
    int id;
    float fee;
    int found = 0;

    printf("\nEnter Student ID : ");
    scanf("%d",&id);

    printf("Enter Fee Amount : ");
    scanf("%f",&fee);

    for(int i=0; i<studentCount; i++)
    {
        if(students[i].id==id)
        {
            students[i].feeDue = fee;

            saveStudents();

            found = 1;

            printf("\nFee Updated Successfully.\n");
            break;
        }
    }

    if(found==0)
    {
        printf("\nStudent Not Found.\n");
    }
}

void viewCheckInOut()
{
    FILE *fp = fopen("attendance.txt","r");
    char line[200];

    if(fp==NULL)
    {
        printf("\nNo Attendance Record.\n");
        return;
    }

    printf("\n====== CHECK IN / CHECK OUT ======\n\n");

    while(fgets(line,sizeof(line),fp))
    {
        printf("%s",line);
    }

    fclose(fp);
}

void viewAllPaymentHistory()
{
    FILE *fp = fopen("payment.txt","r");
    char line[200];

    if(fp==NULL)
    {
        printf("\nNo Payment History.\n");
        return;
    }

    printf("\n====== PAYMENT HISTORY ======\n\n");

    while(fgets(line,sizeof(line),fp))
    {
        printf("%s",line);
    }

    fclose(fp);
}

void viewLateComplaints()
{
    FILE *fp = fopen("Late_Entry.txt","r");
    char line[200];

    if(fp == NULL)
    {
        printf("\nNo Late Entry Complaint Found.\n");
        return;
    }

    printf("\n====== LATE ENTRY COMPLAINTS ======\n\n");

    while(fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    fclose(fp);
}
void addFood()
{
    Food f;

    f.foodId = foodCount + 1;

    printf("\n========== ADD FOOD ==========\n");

    printf("Enter Food Name : ");
    scanf("%s", f.foodName);

    printf("Enter Food Price : ");
    scanf("%f", &f.price);

    foods[foodCount] = f;
    foodCount++;

    saveFood();

    printf("\nFood Added Successfully.\n");
}

void viewFood()
{
    if(foodCount==0)
    {
        printf("\nNo Food Available.\n");
        return;
    }

    printf("\n========== FOOD MENU ==========\n");

    for(int i=0; i<foodCount; i++)
    {
        printf("\nFood ID : %d\n", foods[i].foodId);
        printf("Food Name : %s\n", foods[i].foodName);
        printf("Price : %.2f\n", foods[i].price);
    }
}

void updateFoodPrice()
{
    int id;
    float price;
    int found = 0;

    printf("\nEnter Food ID : ");
    scanf("%d",&id);

    printf("Enter New Price : ");
    scanf("%f",&price);

    for(int i=0; i<foodCount; i++)
    {
        if(foods[i].foodId == id)
        {
            foods[i].price = price;

            saveFood();

            printf("\nFood Price Updated Successfully.\n");

            found = 1;
            break;
        }
    }

    if(found==0)
    {
        printf("\nFood Not Found.\n");
    }
}

void viewAllOrders()
{
    if(orderCount==0)
    {
        printf("\nNo Orders.\n");
        return;
    }

    printf("\n========== ALL FOOD ORDERS ==========\n");

    for(int i=0; i<orderCount; i++)
    {
        printf("\nStudent ID : %d\n",
               orders[i].studentId);

        printf("Food ID : %d\n",
               orders[i].foodId);

        printf("Quantity : %d\n",
               orders[i].quantity);

        printf("Bill : %.2f\n",
               orders[i].totalBill);

        printf("Status : %s\n",
               orders[i].paid?"Paid":"Pending");
    }
}

void adminMenu()
{
    int choice;

    while(1)
    {
        system("cls");
        printf("\n========== ADMIN MENU ==========\n");

        printf("1. Add Room\n");
        printf("2. View Rooms\n");
        printf("3. Allocate Room\n");
        printf("4. Remove Room\n");
        printf("5. Vacate Room\n");
        printf("6. View Students\n");
        printf("7. Update Fee\n");
        printf("8. View Complaints\n");
        printf("9. Add Notice\n");
        printf("10. Delete Notice\n");
        printf("11. Mark Attendance\n");
        printf("12. Search Student\n");
        printf("13. View Leave Request\n");
        printf("14. View Visitor Request\n");
        printf("15. Report\n");
        printf("16. View Check In / Check Out\n");
        printf("17. View Payment History\n");
        printf("18. View Late Entry Complaints\n");
        printf("0. Logout\n");

        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            addRoom();
            pauseScreen();
            break;

        case 2:
            viewRooms();
            pauseScreen();
            break;

        case 3:
            allocateRoom();
            pauseScreen();
            break;

        case 4:
            removeRoom();
            pauseScreen();
            break;

        case 5:
            vacateRoom();
            pauseScreen();
            break;

        case 6:
            viewStudents();
            pauseScreen();
            break;

        case 7:
            UpdateFee();
            pauseScreen();
            break;

        case 8:
            viewComplaints();
            pauseScreen();
            break;

        case 9:
            addNotice();
            pauseScreen();
            break;

        case 10:
            deleteNotice();
            pauseScreen();
            break;

        case 11:
            markAttendance();
            pauseScreen();
            break;

        case 12:
            searchStudent();
            pauseScreen();
            break;

        case 13:
            viewLeaveRequest();
            pauseScreen();
            break;

        case 14:
            viewVisitorRequest();
            pauseScreen();
            break;

        case 15:
            studentReport();
            pauseScreen();
            break;

        case 16:
            viewCheckInOut();
            pauseScreen();
            break;

        case 17:
            viewAllPaymentHistory();
            pauseScreen();
            break;

        case 18:
            viewLateComplaints();
            pauseScreen();
            break;

        case 0:
            return;

        default:
            printf("\nInvalid Choice.\n");
        }
    }
}

int canteenLogin()
{
    char username[20];
    char password[20];

    printf("\n===== CANTEEN MANAGEMENT SYSTEM =====\n");

    printf("Username : ");
    scanf("%s", username);

    printf("Password : ");
    scanf("%s", password);

    if(strcmp(username,"canteen")==0 &&
            strcmp(password,"1234")==0)
    {
        printf("\nLogin Successful!\n");
        return 1;
    }

    printf("\nInvalid Username or Password!\n");

    return 0;
}
void manageFoodPayment()
{
    int studentId;
    int found = 0;

    printf("\n========== FOOD PAYMENT ==========\n");

    printf("Enter Student ID : ");
    scanf("%d",&studentId);

    for(int i=0; i<orderCount; i++)
    {
        if(orders[i].studentId == studentId &&
                orders[i].paid == 1)
        {
            printf("\nFood ID : %d", orders[i].foodId);
            printf("\nQuantity : %d", orders[i].quantity);
            printf("\nBill : %.2f", orders[i].totalBill);
            printf("\nStatus : Paid\n");

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nNo Paid Payment Found.\n");
    }
}


void canteenManagementSystem()
{
    int choice;

    while(1)
    {
        system("cls");

        printf("\n=====================================\n");
        printf("      CANTEEN MANAGEMENT SYSTEM\n");
        printf("=====================================\n");

        printf("1. Add Food\n");
        printf("2. View Food Menu\n");
        printf("3. Update Food Price\n");
        printf("4. View All Orders\n");
        printf("5. Manage Food Payment\n");
        printf("0. Logout\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            addFood();
            pauseScreen();
            break;

        case 2:
            viewFood();
            pauseScreen();
            break;

        case 3:
            updateFoodPrice();
            pauseScreen();
            break;

        case 4:
            viewAllOrders();
            pauseScreen();
            break;

        case 5:
            manageFoodPayment();
            pauseScreen();
            break;

        case 0:
            return;

        default:
            printf("\nInvalid Choice.\n");
        }
    }
}
int wardenLogin()
{
    char username[20];
    char password[20];

    printf("\n===== WARDEN LOGIN =====\n");

    printf("Username : ");
    scanf("%s",username);

    printf("Password : ");
    scanf("%s",password);

    if(strcmp(username,"warden")==0 &&
            strcmp(password,"1234")==0)
    {
        printf("\nWarden Login Successful!\n");
        return 1;
    }

    printf("\nInvalid Username or Password!\n");

    return 0;
}
void addFoundItem()
{
    LostFound item;

    item.itemId = lostItemCount + 1;

    printf("\n========== ADD FOUND ITEM ==========\n");

    printf("Enter Item Name : ");
    scanf("%s",item.itemName);

    printf("Enter Clue : ");
    scanf("%s",item.clue);

    printf("Enter Found Location : ");
    scanf("%s",item.foundLocation);

    item.claimed = 0;

    lostItems[lostItemCount] = item;
    lostItemCount++;

    saveLostFound();

    printf("\nFound Item Added Successfully.\n");
}
void viewFoundItems()
{
    if(lostItemCount == 0)
    {
        printf("\nNo Found Item Available.\n");
        return;
    }

    printf("\n========== LOST & FOUND ITEMS ==========\n");

    for(int i=0; i<lostItemCount; i++)
    {
        if(lostItems[i].claimed == 0)
        {
            printf("\nItem ID        : %d\n",
                   lostItems[i].itemId);

            printf("Item Name      : %s\n",
                   lostItems[i].itemName);

            printf("Clue           : %s\n",
                   lostItems[i].clue);

            printf("Found Location : %s\n",
                   lostItems[i].foundLocation);

            printf("Status         : Available\n");

            printf("----------------------------------------\n");
        }
    }
}
void searchLostItem()
{
    char keyword[50];
    int found = 0;

    printf("\n========== SEARCH LOST ITEM ==========\n");

    printf("Enter Item Name : ");
    scanf("%s",keyword);

    for(int i=0; i<lostItemCount; i++)
    {
        if(lostItems[i].claimed == 0 &&
                strcmp(lostItems[i].itemName,keyword)==0)
        {
            printf("\nItem Found!\n");

            printf("Item ID        : %d\n",
                   lostItems[i].itemId);

            printf("Item Name      : %s\n",
                   lostItems[i].itemName);

            printf("Clue           : %s\n",
                   lostItems[i].clue);

            printf("Found Location : %s\n",
                   lostItems[i].foundLocation);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nNo Matching Item Found.\n");
    }
}

void claimLostItem()
{
    int itemId;
    char information[200];

    printf("\n========== CLAIM LOST ITEM ==========\n");

    printf("Enter Item ID : ");
    scanf("%d",&itemId);

    int found = -1;

    for(int i=0; i<lostItemCount; i++)
    {
        if(lostItems[i].itemId == itemId &&
                lostItems[i].claimed == 0)
        {
            found = i;
            break;
        }
    }

    if(found == -1)
    {
        printf("\nItem Not Found.\n");
        return;
    }

    printf("\nItem Name : %s\n",
           lostItems[found].itemName);

    printf("Clue : %s\n",
           lostItems[found].clue);

    getchar();

    printf("\nEnter identifying information : ");
    fgets(information,200,stdin);

    information[strcspn(information,"\n")] = 0;

    FILE *fp = fopen("lost_claims.txt","a");

    if(fp == NULL)
    {
        printf("\nFile Error!\n");
        return;
    }

    fprintf(fp,"%d %s\n",
            itemId,
            information);

    fclose(fp);

    printf("\nClaim Request Submitted Successfully.\n");
    printf("Warden will verify your information.\n");
}

void verifyAndReturnItem()
{
    int itemId;
    char claimInfo[200];

    printf("\n========== VERIFY & RETURN ITEM ==========\n");

    FILE *fp = fopen("lost_claims.txt","r");

    if(fp == NULL)
    {
        printf("\nNo Claim Request Found.\n");
        return;
    }

    printf("\n========== CLAIM REQUESTS ==========\n");

    while(fscanf(fp,"%d %[^\n]",
                 &itemId,
                 claimInfo) == 2)
    {
        int found = -1;

        for(int i=0; i<lostItemCount; i++)
        {
            if(lostItems[i].itemId == itemId &&
                    lostItems[i].claimed == 0)
            {
                found = i;
                break;
            }
        }

        if(found != -1)
        {
            printf("\nItem ID : %d\n",itemId);
            printf("Item Name : %s\n",
                   lostItems[found].itemName);

            printf("Stored Clue : %s\n",
                   lostItems[found].clue);

            printf("Student Information : %s\n",
                   claimInfo);

            printf("-----------------------------------\n");

            int choice;

            printf("Does the information match?\n");
            printf("1. Yes - Return Item\n");
            printf("2. No - Reject Claim\n");

            printf("Enter Choice : ");
            scanf("%d",&choice);

            if(choice == 1)
            {
                lostItems[found].claimed = 1;

                saveLostFound();

                printf("\nInformation Matched Successfully!\n");
                printf("Item Returned to Student.\n");
            }
            else
            {
                printf("\nClaim Rejected.\n");
            }
        }
    }

    fclose(fp);
}
void lostFoundManagement()
{
    int choice;

    while(1)
    {
        system("cls");

        printf("\n=====================================\n");
        printf("       LOST & FOUND MANAGEMENT\n");
        printf("=====================================\n");

        printf("1. Add Found Item\n");
        printf("2. View Found Items\n");
        printf("3. Verify & Return Item\n");
        printf("0. Logout\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            addFoundItem();
            pauseScreen();
            break;

        case 2:
            viewFoundItems();
            pauseScreen();
            break;

        case 3:
            verifyAndReturnItem();
            pauseScreen();
            break;

        case 0:
            return;

        default:
            printf("\nInvalid Choice.\n");
        }
    }
}
void viewAllLaundryRequests()
{
    if(laundryCount == 0)
    {
        printf("\nNo Laundry Requests Found.\n");
        return;
    }

    printf("\n========== ALL LAUNDRY REQUESTS ==========\n");

    for(int i = 0; i < laundryCount; i++)
    {
        int studentIndex =
            findStudent(laundryRequests[i].studentId);

        printf("\nRequest ID : %d\n",
               laundryRequests[i].requestId);

        printf("Student ID : %d\n",
               laundryRequests[i].studentId);

        if(studentIndex != -1)
        {
            printf("Student Name : %s\n",
                   students[studentIndex].name);

            printf("Gender       : %s\n",
                   students[studentIndex].gender);
        }

        printf("\nItems:\n");

        for(int j = 0;
                j < laundryRequests[i].itemCount;
                j++)
        {
            printf("  %s - %d\n",
                   laundryRequests[i].items[j].itemName,
                   laundryRequests[i].items[j].quantity);
        }

        printf("Pickup Date : %s\n",
               laundryRequests[i].pickupDate);

        printf("Status      : %s\n",
               laundryRequests[i].status);

        printf("----------------------------------------\n");
    }
}
void updateLaundryStatus()
{
    int requestId;
    int found = -1;
    int choice;

    printf("\n========== UPDATE LAUNDRY STATUS ==========\n");

    printf("Enter Request ID : ");
    scanf("%d", &requestId);

    for(int i = 0; i < laundryCount; i++)
    {
        if(laundryRequests[i].requestId == requestId)
        {
            found = i;
            break;
        }
    }

    if(found == -1)
    {
        printf("\nRequest not found!\n");
        return;
    }

    printf("\nCurrent Status : %s\n",
           laundryRequests[found].status);

    printf("\nSelect New Status:\n");
    printf("1. Received\n");
    printf("2. Washing\n");
    printf("3. Ready\n");
    printf("4. Delivered\n");

    printf("\nEnter Choice : ");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1:
        strcpy(laundryRequests[found].status, "Received");
        break;

    case 2:
        strcpy(laundryRequests[found].status, "Washing");
        break;

    case 3:
        strcpy(laundryRequests[found].status, "Ready");
        break;

    case 4:
        strcpy(laundryRequests[found].status, "Delivered");
        break;

    default:
        printf("\nInvalid Choice.\n");
        return;
    }

    saveLaundry();

    printf("\nLaundry Status Updated Successfully!\n");
}
void laundryManagement()
{
    int choice;

    while(1)
    {
        system("cls");

        printf("\n=====================================\n");
        printf("       LAUNDRY MANAGEMENT\n");
        printf("=====================================\n");

        printf("1. View Laundry Requests\n");
        printf("2. Update Laundry Status\n");
        printf("0. Back\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            viewAllLaundryRequests();
            pauseScreen();
            break;

        case 2:
            updateLaundryStatus();
            pauseScreen();
            break;

        case 0:
            return;

        default:
            printf("\nInvalid Choice.\n");
            pauseScreen();
        }
    }
}

int main()
{
    int choice;
    int index;

    loadStudents();
    loadRooms();
    loadNotices();
    loadComplaints();
    loadFood();
    loadOrders();
    loadLostFound();
    loadLaundry();

    while(1)
    {
        system("cls");
        printf("\n=====================================\n");
        printf("     HOSTEL MANAGEMENT SYSTEM\n");
        printf("=====================================\n");

        printf("1. Student Registration\n");
        printf("2. Student Login\n");
        printf("3. Admin Login\n");
        printf("4. Canteen Management System\n");
        printf("5. Lost & Found Management\n");
        printf("6. Laundry System\n");
        printf("0. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            registerStudent();
            pauseScreen();
            break;
        case 2:

            index = studentLogin();

            if(index != -1)
            {
                studentMenu(index);
            }

            break;

        case 3:

            if(adminLogin())
            {
                adminMenu();
            }

            break;

        case 4:

            if(canteenLogin())
            {
                canteenManagementSystem();
            }

            break;

        case 5:

            if(wardenLogin())
            {
                lostFoundManagement();
            }

            break;

        case 6:

            if(wardenLogin())
            {
                laundryManagement();
            }

            break;

        case 0:

            printf("\nThank You.\n");
            return 0;

        default:

            printf("\nInvalid Choice.\n");
        }
    }

    return 0;
}