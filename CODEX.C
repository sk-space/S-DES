#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<graphics.h>

int i,sel,choice,retreate_choice,total_characters,str_num;
int key[11],p10[11],s1_p10[11],s3_p10[11],subkey1[11],subkey2[11];
int bin[9],l_bin[5],r_bin[5];
int ip[9],l_ip[5],r_ip[5];
char sfname[25];
int view;

int dec_exp_1[9];
int dec_exp_2[9];
int enc_exp_1[9];
int enc_exp_2[9];
int iip[9],iip_f[9];
unsigned char enc_data[1000];

int fk1_l[5],fk1_r[5],fk2_l[5],fk2_r[5];
int p[9],ss[5],p_ss[5],p4_lip_xOr[5],p4_swl_xOr[5];

void menu();
void exit_pro();
void center(int,char[]);

void encryption();
void e_binary_data();
void e_key_block();
void e_key_functions();
void e_p10_blocks();
void e_shift1_p10_blocks();
void e_shift3_p10_blocks();
void e_p8_blocks();
void e_initial_permutation();
void e_outplay();
void e_loading();

void decryption();
void d_binary_data();
void d_key_block();
void d_key_functions();
void d_p10_blocks();
void d_shift1_p10_blocks();
void d_shift3_p10_blocks();
void d_p8_blocks();
void d_initial_permutation();
void d_outplay();
void d_loading();

void main()
{
    int gd,gm,maxx,maxy;
    gd=DETECT;
    initgraph(&gd,&gm,"..//bgi");

    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    settextstyle(6,0,5);
    setcolor(14);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    line(10,100,630,100);
    line(10,101,630,101);
    line(40,110,600,110);
    line(40,165,600,165);
    line(10,175,630,175);
    line(10,176,630,176);
    line(40,110,40,165);
    line(600,165,600,110);
    settextstyle(1,0,4);
    setcolor(14);
    outtextxy(320,130,"Data Encryption and Decryption");
    outtextxy(320,131,"Data Encryption and Decryption");
    center(15,"-----------------------------------------------------------");
    center(16,"Mini Project by Binay Chakradhar and Suman Kaiti\n");
    center(17,"-----------------------------------------------------------");
    center(25,"Press any key to go to Menu...");
    getch();
    menu();
    getch();
}

void run_again()
{
    int option;
start:
    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    settextstyle(6,0,5);
    setcolor(14);
    outtextxy(320,80,"-||  Menu Option  ||-");
    outtextxy(320,80,"Menu Option");
    setcolor(15);
    line(50,120,590,120);
    settextstyle(1,0,3);
    outtextxy(290,160,"1. Run Again");
    outtextxy(253,200,"2. Exit");
    line(50,300,590,300);
    center(24,"Enter your choice: ");
    scanf("%d",&option);
    if(option==1)
    {
        menu();
    }
    else if(option==2)
    {
        exit_pro();
    }
    else
    {
        clrscr();
        setfillstyle(1,1);
        bar(0,0,800,800);
        setfillstyle(1,9);
        bar(10,10,630,470);
        setbkcolor(9);
        outtextxy(320,250,"Invalid Option !!!");
        center(25,"Press any key to go to menu...");
        getch();
        goto start;
    }
}

void menu()
{
top:
    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    settextstyle(1,0,5);
    setcolor(14);
    outtextxy(320,80,"-|| HOME MENU ||-");
    outtextxy(321,80,"-|| HOME MENU ||-");
    setcolor(15);
    line(50,120,590,120);
    settextstyle(1,0,3);
    outtextxy(290,160,"1. Encryption");
    outtextxy(290,200,"2. Decryption");
    outtextxy(250,240,"3. Exit");
    line(50,340,590,340);
    center(25,"Enter your choice: ");
    scanf("%d",&choice);
    retreate_choice=choice;
    switch(choice)
    {
    case 1:
        clrscr();
        setfillstyle(1,1);
        bar(0,0,800,800);
        setfillstyle(1,9);
        bar(10,10,630,470);
        setbkcolor(9);
        view=0;
        e_key_block();
        e_key_functions();
        e_binary_data();
        e_outplay();
        break;

    case 2:
        clrscr();
        setfillstyle(1,1);
        bar(0,0,800,800);
        setfillstyle(1,9);
        bar(10,10,630,470);
        setbkcolor(9);
        view=0;
        d_key_block();
        d_key_functions();
        d_binary_data();
        d_outplay();
        break;

    case 3:
        exit_pro();

    default:
        clrscr();
        setfillstyle(1,1);
        bar(0,0,800,800);
        setfillstyle(1,9);
        bar(10,10,630,470);
        setbkcolor(9);
        outtextxy(320,250,"Invalid Option !!!");
        center(25,"Press any key to go to menu...");
        getch();
        goto top;
    }
}

/**************************ENCRYPTION CODE STARTS ************************************/
void e_key_block()
{
    char pwd[256]= {0};
    char ch;
    int pos=0,pwdlen,total_ascii=0,keys[11];
    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    {
        //start
        center(13,"Enter the password : ");
        do
        {
            ch=getch();
            if(isprint(ch))
            {
                pwd[pos++]=ch;
                printf("%c", '*');
            }
            else if(ch==8 && pos)
            {
                pwd[--pos]='\0';
                printf("%s","\b \b");
            }
        }
        while(ch!=13 && pos<256);
    }

    pwdlen=strlen(pwd);

    for(i=0; i<pwdlen; i++)
    {
        ch=pwd[i];
        total_ascii=total_ascii+ch;
    }

    for(i=1; i<11; i++)
    {
        keys[i]=total_ascii%2;
        total_ascii=total_ascii/2;
    }

    for(i=1; i<11; i++)
    {
        key[1]=keys[3];
        key[2]=keys[4];
        key[3]=keys[7];
        key[4]=keys[1];
        key[5]=keys[5];
        key[6]=keys[9];
        key[7]=keys[6];
        key[8]=keys[2];
        key[9]=keys[10];
        key[10]=keys[8];
    }
}

void e_key_functions()
{
    e_p10_blocks();
    e_shift1_p10_blocks();
    e_shift3_p10_blocks();
    e_p8_blocks();
}

void e_p10_blocks()
{
    p10[1]=key[3];
    p10[2]=key[5];
    p10[3]=key[2];
    p10[4]=key[7];
    p10[5]=key[4];

    p10[6]=key[10];
    p10[7]=key[1];
    p10[8]=key[9];
    p10[9]=key[8];
    p10[10]=key[6];
}

void e_shift1_p10_blocks()
{
    int ls1_p10[5],rs1_p10[5];
    ls1_p10[1]=p10[2];
    ls1_p10[2]=p10[3];
    ls1_p10[3]=p10[4];
    ls1_p10[4]=p10[5];
    ls1_p10[5]=p10[1];

    rs1_p10[1]=p10[7];
    rs1_p10[2]=p10[8];
    rs1_p10[3]=p10[9];
    rs1_p10[4]=p10[10];
    rs1_p10[5]=p10[6];

    s1_p10[1]=ls1_p10[1];
    s1_p10[2]=ls1_p10[2];
    s1_p10[3]=ls1_p10[3];
    s1_p10[4]=ls1_p10[4];
    s1_p10[5]=ls1_p10[5];
    s1_p10[6]=rs1_p10[1];
    s1_p10[7]=rs1_p10[2];
    s1_p10[8]=rs1_p10[3];
    s1_p10[9]=rs1_p10[4];
    s1_p10[10]=rs1_p10[5];
}

void e_shift3_p10_blocks()
{
    int ls3_p10[5],rs3_p10[5];
    ls3_p10[1]=p10[4];
    ls3_p10[2]=p10[5];
    ls3_p10[3]=p10[1];
    ls3_p10[4]=p10[2];
    ls3_p10[5]=p10[3];

    rs3_p10[1]=p10[9];
    rs3_p10[2]=p10[10];
    rs3_p10[3]=p10[6];
    rs3_p10[4]=p10[7];
    rs3_p10[5]=p10[8];

    s3_p10[1]=ls3_p10[1];
    s3_p10[2]=ls3_p10[2];
    s3_p10[3]=ls3_p10[3];
    s3_p10[4]=ls3_p10[4];
    s3_p10[5]=ls3_p10[5];
    s3_p10[6]=rs3_p10[1];
    s3_p10[7]=rs3_p10[2];
    s3_p10[8]=rs3_p10[3];
    s3_p10[9]=rs3_p10[4];
    s3_p10[10]=rs3_p10[5];
}

void e_p8_blocks()
{
    subkey1[1]=s1_p10[6];
    subkey1[2]=s1_p10[3];
    subkey1[3]=s1_p10[7];
    subkey1[4]=s1_p10[4];
    subkey1[5]=s1_p10[8];
    subkey1[6]=s1_p10[5];
    subkey1[7]=s1_p10[10];
    subkey1[8]=s1_p10[9];

    subkey2[1]=s3_p10[6];
    subkey2[2]=s3_p10[3];
    subkey2[3]=s3_p10[7];
    subkey2[4]=s3_p10[4];
    subkey2[5]=s3_p10[8];
    subkey2[6]=s3_p10[5];
    subkey2[7]=s3_p10[10];
    subkey2[8]=s3_p10[9];
}

void e_binary_data()
{
    int l_bin[5],r_bin[5],sel,i=0;
    float value;
    char ch,str[10000],sfname[30];
    FILE *fp;
    fflush(stdin);
e_top:
    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    settextstyle(1,0,5);
    setcolor(14);
    outtextxy(320,80,"-|| Encryption Option ||-");
    outtextxy(320,80,"| Encryption Option |");
    setcolor(15);
    line(50,120,590,120);
    settextstyle(1,0,3);
    outtextxy(300,160,"1. Encrypt File Message");
    outtextxy(315,200,"2. Encrypt Typed Message");
    outtextxy(243,240,"3. Main Menu");
    outtextxy(202,280,"4. Exit");
    line(50,340,590,340);
    center(25,"Enter your choice: ");
    scanf("%d",&sel);
    if(sel==1)
    {
        setfillstyle(1,1);
        bar(0,0,800,800);
        setfillstyle(1,9);
        bar(10,10,630,470);
        setbkcolor(9);
        settextstyle(6,0,5);
        fflush(stdin);
        center(8,"Enter file name: ");
        gets(sfname);
        if((fp=fopen(sfname,"r"))==NULL)
        {
            outtextxy(320,220,"Invalid File Name !!!");
            delay(1500);
            goto e_top;
        }

        while(1)
        {
            ch=fgetc(fp);
            if(ch==EOF)
                break;
            else
            {
                str[i++]=ch;
                putch(ch);
            }
        }

        total_characters=strlen(str);
        setfillstyle(1,1);
        bar(0,0,800,800);
        setfillstyle(1,9);
        bar(10,10,630,470);
        setbkcolor(9);
        settextstyle(1,0,1);
        printf("\n\tMessage in the file is:");
        setcolor(15);
        line(40,165,600,165);
        printf("\n\n\t");
        for(str_num=0; str_num<total_characters; str_num++)
        {
            printf("%c",str[str_num]);
        }
        center(25,"Press any key to start encryption...");
        getch();
    }

    else if(sel==2)
    {
re:
        clrscr();
        setfillstyle(1,1);
        bar(0,0,800,800);
        setfillstyle(1,9);
        bar(10,10,630,470);
        setbkcolor(9);
        settextstyle(6,0,5);
        setcolor(14);
        fflush(stdin);
        printf("\n\n\tEnter your message : ");
        gets(str);
        total_characters=strlen(str);
        printf("\n\n\n\tEnter File Name To Save Message: ");
        gets(sfname);
        if((fp=fopen(sfname,"wb"))==NULL)
        {
            outtextxy(320,220,"Invalid File Name !!!");
            delay(1500);
re_enter:
            setfillstyle(1,1);
            bar(0,0,800,800);
            setfillstyle(1,9);
            bar(10,10,630,470);
            setbkcolor(9);
            settextstyle(1,0,5);
            setcolor(14);
            outtextxy(320,80,"-| Re-Option |-");
            outtextxy(321,80,"| Re-Option |");
            setcolor(15);
            line(50,120,590,120);
            settextstyle(1,0,3);
            outtextxy(300,160,"1. Re-Enter Details");
            outtextxy(310,200,"2. Encryption option");
            line(50,260,590,260);
            center(25,"Enter your choice: ");
            scanf("%d",&sel);
            if(sel==1)
            {
                goto re;
            }
            else if(sel==2)
            {
                e_binary_data();
            }
            else
            {
                clrscr();
                setfillstyle(1,1);
                bar(0,0,800,800);
                setfillstyle(1,9);
                bar(10,10,630,470);
                setbkcolor(9);
                outtextxy(320,250,"Invalid Option !!!");
                center(25,"Press any key to go to menu...");
                getch();
                goto re_enter;
            }
        }
    }

    else if(sel==3)
    {
        menu();
    }

    else if(sel==4)
    {
        exit_pro();
    }

    else
    {
        clrscr();
        setfillstyle(1,1);
        bar(0,0,800,800);
        setfillstyle(1,9);
        bar(10,10,630,470);
        setbkcolor(9);
        outtextxy(320,250,"Invalid Option !!!");
        center(25,"Press any key to go to menu...");
        getch();
        goto e_top;
    }

    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    center(12,"Data Verification and Password Validation in progress...");
    center(16,"Please Wait...");
    if(total_characters<=100)
    {
        delay(3000);
    }
    else if(total_characters>100 && total_characters<=500)
    {
        delay(3500);
    }
    else if(total_characters>500 && total_characters<=2500)
    {
        delay(4000);
    }
    else
    {
        delay(4500);
    }

    for(str_num=0; str_num<total_characters; str_num++)
    {
        ch=str[str_num];
        fprintf(fp,"%c",ch);
        for(i=8; i>0; i--)
        {
            bin[i]=ch%2;
            ch=ch/2;
        }

        l_bin[1]=bin[1];
        l_bin[2]=bin[2];
        l_bin[3]=bin[3];
        l_bin[4]=bin[4];

        r_bin[1]=bin[5];
        r_bin[2]=bin[6];
        r_bin[3]=bin[7];
        r_bin[4]=bin[8];

        encryption();
    }

    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    settextstyle(6,0,5);
    setcolor(14);
    fflush(stdin);
    for(view=0; view<total_characters; view++)
    {
        if(enc_data[view]==10 || enc_data[view]==0)
        {
            center(10,"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
	    center(12,"----- This PASSWORD can't be used to encrypt or decrypt this message -----");
            center(13,"-------------------------- Use another PASSWORD --------------------------");
            center(14,"------------- Please run the program with another PASSWORD ---------------");
            center(16,"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");
            fclose(fp);
            center(25,"Press any key to go to Menu...");
            getch();
            menu();
        }
    }

    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    center(12,"Verification Complete...");
    center(16,"Press any key to start encryption...");
    getch();
    e_loading();
    fclose(fp);
}

void e_initial_permutation()
{
    ip[1]=bin[2];
    ip[2]=bin[6];
    ip[3]=bin[3];
    ip[4]=bin[1];
    ip[5]=bin[4];
    ip[6]=bin[8];
    ip[7]=bin[5];
    ip[8]=bin[7];

    l_ip[1]=ip[1];
    l_ip[2]=ip[2];
    l_ip[3]=ip[3];
    l_ip[4]=ip[4];

    r_ip[1]=ip[5];
    r_ip[2]=ip[6];
    r_ip[3]=ip[7];
    r_ip[4]=ip[8];
}

/************* FUNCTIONS fK,SW,K *******************/
void e_expansion_permutation_1()
{
    enc_exp_1[1]=r_ip[4];
    enc_exp_1[2]=r_ip[1];
    enc_exp_1[3]=r_ip[2];
    enc_exp_1[4]=r_ip[3];
    enc_exp_1[5]=r_ip[2];
    enc_exp_1[6]=r_ip[3];
    enc_exp_1[7]=r_ip[4];
    enc_exp_1[8]=r_ip[1];
}

void e_xOr_k1_enc_exp1()
{
    int r_xOr[9];
    //XOR of 8-bit right expansion permutation string with 8-bit key1
    for(i=1; i<9; i++)
    {
        if(enc_exp_1[i]==subkey1[i])
            r_xOr[i]=0;
        else
            r_xOr[i]=1;
    }

    for(i=1; i<9; i++)
    {
        p[i]=r_xOr[i];
    }
}

void e_s_boxes()
{
    int s0[4][4],s1[4][4],s0_bin[2],row0,column0,row1,column1,sl[3],sr[3],pp[2][4];
    int b01,b02,b03,b04,b11,b12,b13,b14;
    int s0_value,s1_value;
    //S0 S-Box in matrix form
    s0[0][0]=1;     s0[0][1]=0;     s0[0][2]=3;     s0[0][3]=2;
    s0[1][0]=3;     s0[1][1]=2;     s0[1][2]=1;     s0[1][3]=0;
    s0[2][0]=0;     s0[2][1]=2;     s0[2][2]=1;     s0[2][3]=3;
    s0[3][0]=3;     s0[3][1]=1;     s0[3][2]=3;     s0[3][3]=2;

    //S1 S-Box in matrix form
    s1[0][0]=0;     s1[0][1]=1;     s1[0][2]=2;     s1[0][3]=3;
    s1[1][0]=2;     s1[1][1]=0;     s1[1][2]=1;     s1[1][3]=3;
    s1[2][0]=3;     s1[2][1]=0;     s1[2][2]=1;     s1[2][3]=0;
    s1[3][0]=2;     s1[3][1]=1;     s1[3][2]=0;     s1[3][3]=3;

    //XOR data in matrix form
    pp[0][0]=p[1];      pp[0][1]=p[2];      pp[0][2]=p[3];      pp[0][3]=p[4];
    pp[1][0]=p[5];      pp[1][1]=p[6];      pp[1][2]=p[7];      pp[1][3]=p[8];

    b01=pp[0][0],b02=pp[0][1],b03=pp[0][2],b04=pp[0][3];
    b11=pp[1][0],b12=pp[1][1],b13=pp[1][2],b14=pp[1][3];

    //Binary to Decimal conversion
    //For row0
    if(b01==0&&b04==0)
        row0=0;
    else if(b01==0&&b04==1)
        row0=1;
    else if(b01==1&&b04==0)
        row0=2;
    else
        row0=3;

    //For column0
    if(b02==0&&b03==0)
        column0=0;
    else if(b02==0&&b03==1)
        column0=1;
    else if(b02==1&&b03==0)
        column0=2;
    else
        column0=3;

    //For row1
    if(b11==0&&b14==0)
        row1=0;
    else if(b11==0&&b14==1)
        row1=1;
    else if(b11==1&&b14==0)
        row1=2;
    else
        row1=3;

    //For column1
    if(b12==0&&b13==0)
        column1=0;
    else if(b12==0&&b13==1)
        column1=1;
    else if(b12==1&&b13==0)
        column1=2;
    else
        column1=3;

    //Comparing the row and column with S-Box data
    s0_value=s0[row0][column0];
    s1_value=s1[row1][column1];

    for(i=2; i>0; i--)
    {
        sl[i]=s0_value%2;
        s0_value=s0_value/2;
    }

    for(i=2; i>0; i--)
    {
        sr[i]=s1_value%2;
        s1_value=s1_value/2;
    }

    ss[1]=sl[1];
    ss[2]=sl[2];
    ss[3]=sr[1];
    ss[4]=sr[2];
}

void e_p4_block() // THIS IS THE F1(R, SW) FUNCTIONS FINAL OUTPUT
{
    p_ss[1]=ss[2];
    p_ss[2]=ss[4];
    p_ss[3]=ss[3];
    p_ss[4]=ss[1];
}

void e_xOr_p4_enc_lip()
{
    for(i=1; i<5; i++)
    {
        if(l_ip[i]==p_ss[i])
        {
            p4_lip_xOr[i]=0;
        }
        else
        {
            p4_lip_xOr[i]=1;
        }
    }
}

void e_fk1()
{
    e_expansion_permutation_1();
    e_xOr_k1_enc_exp1();
    e_s_boxes();
    e_p4_block();
    e_xOr_p4_enc_lip();

    fk1_l[1]=p4_lip_xOr[1];
    fk1_l[2]=p4_lip_xOr[2];
    fk1_l[3]=p4_lip_xOr[3];
    fk1_l[4]=p4_lip_xOr[4];

    fk1_r[1]=r_ip[1];
    fk1_r[2]=r_ip[2];
    fk1_r[3]=r_ip[3];
    fk1_r[4]=r_ip[4];
}

void e_swap()
{
    fk1_l[1]=r_ip[1];
    fk1_l[2]=r_ip[2];
    fk1_l[3]=r_ip[3];
    fk1_l[4]=r_ip[4];

    fk1_r[1]=p4_lip_xOr[1];
    fk1_r[2]=p4_lip_xOr[2];
    fk1_r[3]=p4_lip_xOr[3];
    fk1_r[4]=p4_lip_xOr[4];
}

void e_expansion_permutation_2()
{
    enc_exp_2[1]=fk1_r[4];
    enc_exp_2[2]=fk1_r[1];
    enc_exp_2[3]=fk1_r[2];
    enc_exp_2[4]=fk1_r[3];
    enc_exp_2[5]=fk1_r[2];
    enc_exp_2[6]=fk1_r[3];
    enc_exp_2[7]=fk1_r[4];
    enc_exp_2[8]=fk1_r[1];
}

void e_xOr_k2_enc_exp2()
{
    int r_xOr[9];
    //XOR of 8-bit right expansion permutation string with 8-bit key1
    for(i=1; i<9; i++)
    {
        if(enc_exp_2[i]==subkey2[i])
            r_xOr[i]=0;
        else
            r_xOr[i]=1;
    }

    for(i=1; i<9; i++)
    {
        p[i]=r_xOr[i];
    }
}

void e_xOr_p4_swl()
{
    for(i=1; i<5; i++)
    {
        if(fk1_l[i]==p_ss[i])
        {
            p4_swl_xOr[i]=0;
        }
        else
        {
            p4_swl_xOr[i]=1;
        }
    }
}

void e_fk2()
{
    e_expansion_permutation_2();
    e_xOr_k2_enc_exp2();
    e_s_boxes();
    e_p4_block();
    e_xOr_p4_swl();
}

void e_i_initial_permutation()
{
    char apple;
    int iip_left_block[5],iip_right_block[5],iip_data[9];
    int final_data;

    iip[1]=p4_swl_xOr[1];
    iip[2]=p4_swl_xOr[2];
    iip[3]=p4_swl_xOr[3];
    iip[4]=p4_swl_xOr[4];

    iip[5]=fk1_r[1];
    iip[6]=fk1_r[2];
    iip[7]=fk1_r[3];
    iip[8]=fk1_r[4];

    iip_f[1]=iip[4];
    iip_f[2]=iip[1];
    iip_f[3]=iip[3];
    iip_f[4]=iip[5];
    iip_f[5]=iip[7];
    iip_f[6]=iip[2];
    iip_f[7]=iip[8];
    iip_f[8]=iip[6];

    //BINARY TO DECIMAL CONVERSION
    final_data=iip_f[1]*pow(2,7)+iip_f[2]*pow(2,6)+iip_f[3]*pow(2,5)+iip_f[4]*pow(2,4)+iip_f[5]*pow(2,3)+iip_f[6]*pow(2,2)+iip_f[7]*pow(2,1)+iip_f[8]*pow(2,0);
    enc_data[view]=final_data;
    view++;
}

void encryption()
{
    e_initial_permutation();
    e_fk1();
    e_swap();
    e_fk2();
    e_i_initial_permutation();
}

void e_outplay()
{
    FILE *fp;
    int str[10000];
    clrscr();
enter:
    fflush(stdin);
    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    printf("\n\n\tEnter the output file name: ");
    gets(sfname);
    if((fp=fopen(sfname,"wb"))==NULL)
    {
        outtextxy(320,230,"Invalid File Name !!!");
        delay(1500);
re_enter:
        setfillstyle(1,1);
        bar(0,0,800,800);
        setfillstyle(1,9);
        bar(10,10,630,470);
        setbkcolor(9);
        settextstyle(6,0,5);
        setcolor(14);
        outtextxy(320,80,"-| Re-Option |-");
        outtextxy(321,81,"-| Re-Option |-");
        setcolor(15);
        line(50,120,590,120);
        settextstyle(1,0,3);
        outtextxy(350,160,"1. Re-Enter File Name");
        outtextxy(295,200,"2. Main Menu");
        outtextxy(255,240,"3. Exit");
        line(50,320,590,320);
        center(25,"Enter your choice: ");
        scanf("%d",&sel);
        if(sel==1)
        {
            clrscr();
            fclose(fp);
            goto enter;
        }
        else if(sel==2)
        {
            fclose(fp);
            menu();
        }
        else if(sel==3)
        {
            fclose(fp);
            exit_pro();
        }
        else
        {
            clrscr();
            setfillstyle(1,1);
            bar(0,0,800,800);
            setfillstyle(1,9);
            bar(10,10,630,470);
            setbkcolor(9);
            outtextxy(320,250,"Invalid Option !!!");
            center(25,"Press any key to go to menu...");
            getch();
            goto re_enter;
        }
    }

    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    setcolor(14);
    settextstyle(1,0,3);
    outtextxy(200,30,"Final Encrypted output is :");
    center(5,"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
    printf("\n\n\t");
    for(view=0; view<total_characters; view++)
    {
        printf("%c",enc_data[view]);
        fprintf(fp,"%c",enc_data[view]);
    }
    center(19,"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");
    delay(1000);
    center(21,"**************** Your message file had been Encrypted ******************");
    center(22,"****************** Check the output file to confirm ********************");
    center(23,"***************************** THANK YOU ********************************");
    delay(2000);
    fclose(fp);
    center(25,"Press any key to continue...");
    getch();
    run_again();
    getch();
}
/**************************ENCRYPTION CODE ENDS ************************************/

/**************************DECRYPTION CODE STARTS ************************************/
void d_key_block()
{
    char pwd[256]= {0};
    char ch;
    int pos=0,pwdlen,total_ascii=0,keys[11];
    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    {
        //start
        center(10,"Enter the password : ");
        do
        {
            ch=getch();
            if(isprint(ch))
            {
                pwd[pos++]=ch;
                printf("%c", '*');
            }
            else if(ch==8 && pos)
            {
                pwd[--pos]='\0';
                printf("%s","\b \b");
            }
        }
        while(ch!=13 && pos<256);
    }

    pwdlen=strlen(pwd);

    for(i=0; i<pwdlen; i++)
    {
        ch=pwd[i];
        total_ascii=total_ascii+ch;
    }

    for(i=1; i<11; i++)
    {
        keys[i]=total_ascii%2;
        total_ascii=total_ascii/2;
    }

    for(i=1; i<11; i++)
    {
        key[1]=keys[3];
        key[2]=keys[4];
        key[3]=keys[7];
        key[4]=keys[1];
        key[5]=keys[5];
        key[6]=keys[9];
        key[7]=keys[6];
        key[8]=keys[2];
        key[9]=keys[10];
        key[10]=keys[8];
    }
}

void d_key_functions()
{
    d_p10_blocks();
    d_shift1_p10_blocks();
    d_shift3_p10_blocks();
    d_p8_blocks();
}

void d_p10_blocks()
{
    p10[1]=key[3];
    p10[2]=key[5];
    p10[3]=key[2];
    p10[4]=key[7];
    p10[5]=key[4];

    p10[6]=key[10];
    p10[7]=key[1];
    p10[8]=key[9];
    p10[9]=key[8];
    p10[10]=key[6];
}

void d_shift1_p10_blocks()
{
    int ls1_p10[5],rs1_p10[5];
    ls1_p10[1]=p10[2];
    ls1_p10[2]=p10[3];
    ls1_p10[3]=p10[4];
    ls1_p10[4]=p10[5];
    ls1_p10[5]=p10[1];

    rs1_p10[1]=p10[7];
    rs1_p10[2]=p10[8];
    rs1_p10[3]=p10[9];
    rs1_p10[4]=p10[10];
    rs1_p10[5]=p10[6];

    s1_p10[1]=ls1_p10[1];
    s1_p10[2]=ls1_p10[2];
    s1_p10[3]=ls1_p10[3];
    s1_p10[4]=ls1_p10[4];
    s1_p10[5]=ls1_p10[5];
    s1_p10[6]=rs1_p10[1];
    s1_p10[7]=rs1_p10[2];
    s1_p10[8]=rs1_p10[3];
    s1_p10[9]=rs1_p10[4];
    s1_p10[10]=rs1_p10[5];
}

void d_shift3_p10_blocks()
{
    int ls3_p10[5],rs3_p10[5];
    ls3_p10[1]=p10[4];
    ls3_p10[2]=p10[5];
    ls3_p10[3]=p10[1];
    ls3_p10[4]=p10[2];
    ls3_p10[5]=p10[3];

    rs3_p10[1]=p10[9];
    rs3_p10[2]=p10[10];
    rs3_p10[3]=p10[6];
    rs3_p10[4]=p10[7];
    rs3_p10[5]=p10[8];

    s3_p10[1]=ls3_p10[1];
    s3_p10[2]=ls3_p10[2];
    s3_p10[3]=ls3_p10[3];
    s3_p10[4]=ls3_p10[4];
    s3_p10[5]=ls3_p10[5];
    s3_p10[6]=rs3_p10[1];
    s3_p10[7]=rs3_p10[2];
    s3_p10[8]=rs3_p10[3];
    s3_p10[9]=rs3_p10[4];
    s3_p10[10]=rs3_p10[5];
}

void d_p8_blocks()
{
    subkey1[1]=s1_p10[6];
    subkey1[2]=s1_p10[3];
    subkey1[3]=s1_p10[7];
    subkey1[4]=s1_p10[4];
    subkey1[5]=s1_p10[8];
    subkey1[6]=s1_p10[5];
    subkey1[7]=s1_p10[10];
    subkey1[8]=s1_p10[9];

    subkey2[1]=s3_p10[6];
    subkey2[2]=s3_p10[3];
    subkey2[3]=s3_p10[7];
    subkey2[4]=s3_p10[4];
    subkey2[5]=s3_p10[8];
    subkey2[6]=s3_p10[5];
    subkey2[7]=s3_p10[10];
    subkey2[8]=s3_p10[9];
}

void d_binary_data()
{
    int l_bin[5],r_bin[5],i=0;
    unsigned char str[10000],ch,fname[25];
    FILE *fp;
d_top:
    fflush(stdin);
    clrscr();
    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    center(8,"Enter file name: ");
    gets(fname);
    if((fp=fopen(fname,"rb"))==NULL)
    {
        outtextxy(320,230,"Invalid File Name !!!");
        delay(1500);
re_top:
        setfillstyle(1,1);
        bar(0,0,800,800);
        setfillstyle(1,9);
        bar(10,10,630,470);
        setbkcolor(9);
        settextstyle(6,0,5);
        setcolor(14);
        outtextxy(320,80,"-|| Decryption Option ||-");
        outtextxy(320,80,"| Decryption Option |");
        setcolor(15);
        line(50,120,590,120);
        settextstyle(1,0,3);
        outtextxy(300,160,"1. Re-Enter file name");
        outtextxy(250,200,"2. Main Menu");
        outtextxy(210,240,"3. Exit");
        line(50,340,590,340);
        center(25,"Enter your choice: ");
        scanf("%d",&sel);
        if(sel==1)
        {
            fclose(fp);
            goto d_top;
        }
        else if(sel==2)
        {
            fclose(fp);
            menu();
        }
        else if(sel==3)
        {
            exit_pro();
        }
        else
        {
            clrscr();
            setfillstyle(1,1);
            bar(0,0,800,800);
            setfillstyle(1,9);
            bar(10,10,630,470);
            setbkcolor(9);
            outtextxy(320,250,"Invalid Option !!!");
            center(25,"Press any key to go to menu...");
            getch();
            goto re_top;
        }
    }
    fgets(str,10000,fp);
    total_characters=strlen(str);
    printf("\n\n\tMessage in the file is:");
    setcolor(15);
    line(40,180,600,180);
    printf("\n\n\t");
    for(str_num=0; str_num<total_characters; str_num++)
    {
        printf("%c",str[str_num]);
    }
    center(25,"Press any key to start decryption...");
    getch();

    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    center(12,"Data Verification and Password Validation in progress...");
    center(16,"Please Wait...");
    if(total_characters<=100)
    {
        delay(3000);
    }
    else if(total_characters>100 && total_characters<=500)
    {
        delay(4000);
    }
    else if(total_characters>500 && total_characters<=2500)
    {
        delay(5000);
    }
    else
    {
        delay(7000);
    }

    for(str_num=0; str_num<total_characters; str_num++)
    {
        ch=str[str_num];
        fprintf(fp,"%c",ch);
        for(i=8; i>0; i--)
        {
            bin[i]=ch%2;
            ch=ch/2;
        }

        l_bin[1]=bin[1];
        l_bin[2]=bin[2];
        l_bin[3]=bin[3];
        l_bin[4]=bin[4];

        r_bin[1]=bin[5];
        r_bin[2]=bin[6];
        r_bin[3]=bin[7];
        r_bin[4]=bin[8];
        decryption();
    }

    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    center(12,"Verification Complete...");
    center(16,"Press any key to start decryption...");
    getch();

    d_loading();
    fclose(fp);
}

void d_initial_permutation()
{
    ip[1]=bin[2];
    ip[2]=bin[6];
    ip[3]=bin[3];
    ip[4]=bin[1];
    ip[5]=bin[4];
    ip[6]=bin[8];
    ip[7]=bin[5];
    ip[8]=bin[7];

    l_ip[1]=ip[1];
    l_ip[2]=ip[2];
    l_ip[3]=ip[3];
    l_ip[4]=ip[4];

    r_ip[1]=ip[5];
    r_ip[2]=ip[6];
    r_ip[3]=ip[7];
    r_ip[4]=ip[8];
}

void d_expansion_permutation_1()
{
    dec_exp_1[1]=r_ip[4];
    dec_exp_1[2]=r_ip[1];
    dec_exp_1[3]=r_ip[2];
    dec_exp_1[4]=r_ip[3];
    dec_exp_1[5]=r_ip[2];
    dec_exp_1[6]=r_ip[3];
    dec_exp_1[7]=r_ip[4];
    dec_exp_1[8]=r_ip[1];
}

void d_xOr_k2_dec_exp1()
{
    int r_xOr[9];
    //XOR of 8-bit right expansion permutation string with 8-bit key1
    for(i=1; i<9; i++)
    {
        if(dec_exp_1[i]==subkey2[i])
            r_xOr[i]=0;
        else
            r_xOr[i]=1;
    }

    for(i=1; i<9; i++)
    {
        p[i]=r_xOr[i];
    }
}

void d_s_boxes()
{
    int s0[4][4],s1[4][4],s0_bin[2],row0,column0,row1,column1,sl[3],sr[3],pp[2][4];
    int b01,b02,b03,b04,b11,b12,b13,b14;
    int s0_value,s1_value;
    //S0 S-Box in matrix form
    //s0[4][4]= {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};

    s0[0][0]=1;     s0[0][1]=0;     s0[0][2]=3;     s0[0][3]=2;
    s0[1][0]=3;     s0[1][1]=2;     s0[1][2]=1;     s0[1][3]=0;
    s0[2][0]=0;     s0[2][1]=2;     s0[2][2]=1;     s0[2][3]=3;
    s0[3][0]=3;     s0[3][1]=1;     s0[3][2]=3;     s0[3][3]=2;

    //S1 S-Box in matrix form
    //s1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};

    s1[0][0]=0;     s1[0][1]=1;     s1[0][2]=2;     s1[0][3]=3;
    s1[1][0]=2;     s1[1][1]=0;     s1[1][2]=1;     s1[1][3]=3;
    s1[2][0]=3;     s1[2][1]=0;     s1[2][2]=1;     s1[2][3]=0;
    s1[3][0]=2;     s1[3][1]=1;     s1[3][2]=0;     s1[3][3]=3;

    //XOR data in matrix form
    pp[0][0]=p[1];      pp[0][1]=p[2];      pp[0][2]=p[3];      pp[0][3]=p[4];
    pp[1][0]=p[5];      pp[1][1]=p[6];      pp[1][2]=p[7];      pp[1][3]=p[8];

    b01=pp[0][0],b02=pp[0][1],b03=pp[0][2],b04=pp[0][3];
    b11=pp[1][0],b12=pp[1][1],b13=pp[1][2],b14=pp[1][3];

    //Binary to Decimal conversion
    //For row0
    if(b01==0&&b04==0)
        row0=0;
    else if(b01==0&&b04==1)
        row0=1;
    else if(b01==1&&b04==0)
        row0=2;
    else
        row0=3;

    //For column0
    if(b02==0&&b03==0)
        column0=0;
    else if(b02==0&&b03==1)
        column0=1;
    else if(b02==1&&b03==0)
        column0=2;
    else
        column0=3;

    //For row1
    if(b11==0&&b14==0)
        row1=0;
    else if(b11==0&&b14==1)
        row1=1;
    else if(b11==1&&b14==0)
        row1=2;
    else
        row1=3;

    //For column1
    if(b12==0&&b13==0)
        column1=0;
    else if(b12==0&&b13==1)
        column1=1;
    else if(b12==1&&b13==0)
        column1=2;
    else
        column1=3;

    //Comparing the row and column with S-Box data
    s0_value=s0[row0][column0];
    s1_value=s1[row1][column1];

    for(i=2; i>0; i--)
    {
        sl[i]=s0_value%2;
        s0_value=s0_value/2;
    }

    for(i=2; i>0; i--)
    {
        sr[i]=s1_value%2;
        s1_value=s1_value/2;
    }

    ss[1]=sl[1];
    ss[2]=sl[2];
    ss[3]=sr[1];
    ss[4]=sr[2];
}

void d_p4_block() // THIS IS THE F1(R, SW) FUNCTIONS FINAL OUTPUT
{
    p_ss[1]=ss[2];
    p_ss[2]=ss[4];
    p_ss[3]=ss[3];
    p_ss[4]=ss[1];
}

void d_xOr_p4_dec_lip()
{
    for(i=1; i<5; i++)
    {
        if(l_ip[i]==p_ss[i])
        {
            p4_lip_xOr[i]=0;
        }
        else
        {
            p4_lip_xOr[i]=1;
        }
    }
}

void d_fk2()
{
    d_expansion_permutation_1();
    d_xOr_k2_dec_exp1();
    d_s_boxes();
    d_p4_block();
    d_xOr_p4_dec_lip();
}

void d_swap()
{
    fk2_l[1]=r_ip[1];
    fk2_l[2]=r_ip[2];
    fk2_l[3]=r_ip[3];
    fk2_l[4]=r_ip[4];

    fk2_r[1]=p4_lip_xOr[1];
    fk2_r[2]=p4_lip_xOr[2];
    fk2_r[3]=p4_lip_xOr[3];
    fk2_r[4]=p4_lip_xOr[4];
}

void d_expansion_permutation_2()
{
    dec_exp_2[1]=fk2_r[4];
    dec_exp_2[2]=fk2_r[1];
    dec_exp_2[3]=fk2_r[2];
    dec_exp_2[4]=fk2_r[3];
    dec_exp_2[5]=fk2_r[2];
    dec_exp_2[6]=fk2_r[3];
    dec_exp_2[7]=fk2_r[4];
    dec_exp_2[8]=fk2_r[1];
}

void d_xOr_k1_dec_exp2()
{
    int r_xOr[9];
    //XOR of 8-bit right expansion permutation string with 8-bit key1
    for(i=1; i<9; i++)
    {
        if(dec_exp_2[i]==subkey1[i])
            r_xOr[i]=0;
        else
            r_xOr[i]=1;
    }

    for(i=1; i<9; i++)
    {
        p[i]=r_xOr[i];
    }
}

void d_xOr_p4_swl()
{
    for(i=1; i<5; i++)
    {
        if(fk2_l[i]==p_ss[i])
        {
            p4_swl_xOr[i]=0;
        }
        else
        {
            p4_swl_xOr[i]=1;
        }
    }
}

void d_fk1()
{
    d_expansion_permutation_2();
    d_xOr_k1_dec_exp2();
    d_s_boxes();
    d_p4_block();
    d_xOr_p4_swl();
}

void d_i_initial_permutation()
{
    char apple;
    int iip_left_block[5],iip_right_block[5],iip_data[9];
    int final_data;

    iip[1]=p4_swl_xOr[1];
    iip[2]=p4_swl_xOr[2];
    iip[3]=p4_swl_xOr[3];
    iip[4]=p4_swl_xOr[4];

    iip[5]=fk2_r[1];
    iip[6]=fk2_r[2];
    iip[7]=fk2_r[3];
    iip[8]=fk2_r[4];

    iip_f[1]=iip[4];
    iip_f[2]=iip[1];
    iip_f[3]=iip[3];
    iip_f[4]=iip[5];
    iip_f[5]=iip[7];
    iip_f[6]=iip[2];
    iip_f[7]=iip[8];
    iip_f[8]=iip[6];

    //BINARY TO DECIMAL CONVERSION
    final_data=iip_f[1]*pow(2,7)+iip_f[2]*pow(2,6)+iip_f[3]*pow(2,5)+iip_f[4]*pow(2,4)+iip_f[5]*pow(2,3)+iip_f[6]*pow(2,2)+iip_f[7]*pow(2,1)+iip_f[8]*pow(2,0);
    enc_data[view]=final_data;
    view++;
}

void decryption()
{
    d_initial_permutation();
    d_fk2();
    d_swap();
    d_fk1();
    d_i_initial_permutation();
}

void d_outplay()
{
    FILE *fp;
enter:
    fflush(stdin);
    clrscr();
    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    settextstyle(6,0,5);
    setcolor(14);
    printf("\n\n\n\tEnter File Name To Store Decrypted Message: ");
    gets(sfname);
    if((fp=fopen(sfname,"wb"))==NULL)
    {
        outtextxy(320,230,"Invalid File Name !!!");
        delay(1500);
re_enter:
        setfillstyle(1,1);
        bar(0,0,800,800);
        setfillstyle(1,9);
        bar(10,10,630,470);
        setbkcolor(9);
        settextstyle(6,0,5);
        setcolor(14);
        outtextxy(320,80,"-| Re-Option |-");
        outtextxy(321,80,"| Re-Option |");
        setcolor(15);
        line(50,120,590,120);
        settextstyle(1,0,3);
        outtextxy(350,160,"1. Re-Enter File Name");
        outtextxy(295,200,"2. Main Menu");
        outtextxy(255,240,"3. Exit");
        line(50,260,590,260);
        center(25,"Enter your choice: ");
        scanf("%d",&sel);
        if(sel==1)
        {
            clrscr();
            fclose(fp);
            goto enter;
        }
        else if(sel==2)
        {
            fclose(fp);
            menu();
        }
        else if(sel==3)
        {
            fclose(fp);
            exit_pro();
        }
        else
        {
            clrscr();
            setfillstyle(1,1);
            bar(0,0,800,800);
            setfillstyle(1,9);
            bar(10,10,630,470);
            setbkcolor(9);
            outtextxy(320,250,"Invalid Option !!!");
            center(25,"Press any key to go to menu...");
            getch();
            goto re_enter;
        }
    }

    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    settextstyle(6,0,4);
    setcolor(14);
    outtextxy(220,30,"Final Decrypted output is :");
    center(5,"-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
    printf("\n\n\t");
    for(view=0; view<total_characters; view++)
    {
        printf("%c",enc_data[view]);
        fprintf(fp,"%c",enc_data[view]);
    }
    center(19,"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");
    delay(1500);
    center(21,"**************** Your message file had been Decrypted ******************");
    center(22,"****************** Check the output file to confirm ********************");
    center(23,"***************************** THANK YOU ********************************");
    delay(2000);
    fclose(fp);
    center(25,"Press any key to continue...");
    fclose(fp);
    getch();
    run_again();
}
/**************************DECRYPTION CODE ENDS ************************************/

void center(int y,char string[])
{
    int x=(80-strlen(string)+1)/2;
    gotoxy(x,y);
    printf("%s",string);
}

void exit_pro()
{
    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    settextstyle(8,0,5);
    setcolor(14);
    outtextxy(320,180,"Thank You For Visiting");
    outtextxy(320,181,"Thank You For Visiting");
    line(10,150,630,150);
    line(10,151,630,151);
    line(10,230,630,230);
    line(10,231,630,231);
    center(24," Press any key to exit ");
    getch();
    exit(0);
}

void e_loading()
{
    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    center(12,"Please wait . . . ");
    rectangle(150,135,480,150);
    for(i=3; i<328; i++)
    {
        setcolor(14);
        line(150+i,138,150+i,147);
        if(total_characters<=25)
        {
            delay(15);
        }
        else if(total_characters>25 && total_characters<=100)
        {
            delay(35);
        }
        else if(total_characters>100 && total_characters<=500)
        {
            delay(85);
        }
        else if(total_characters>500 && total_characters<=2500)
        {
            delay(150);
        }
        else
        {
            delay(210);
        }
    }
    delay(700);
    center(18,"Encryption Completed !");
    delay(1000);
    center(24,"Press any key to continue...");
    getch();
}

void d_loading()
{
    setfillstyle(1,1);
    bar(0,0,800,800);
    setfillstyle(1,9);
    bar(10,10,630,470);
    setbkcolor(9);
    center(12,"Please wait . . . ");
    rectangle(150,135,480,150);
    for(i=3; i<328; i++)
    {
        setcolor(14);
        line(150+i,138,150+i,147);
        if(total_characters<=25)
        {
            delay(15);
        }
        else if(total_characters>25 && total_characters<=100)
        {
            delay(35);
        }
        else if(total_characters>100 && total_characters<=500)
        {
            delay(85);
        }
        else if(total_characters>500 && total_characters<=2500)
        {
            delay(180);
        }
        else
        {
            delay(210);
        }
    }
    delay(700);
    center(18,"Decryption Completed !");
    delay(1000);
    center(24,"Press any key to continue...");
    getch();
}
