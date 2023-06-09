#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
#include <math.h>
using namespace std;

void ConvertBinary(char *hex, char *res)
{
    int k = 0;
    for (int i = 0; hex[i] != '\0'; i++)
    {
        if (hex[i] == '0')
        {
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
        }
        else if (hex[i] == '1')
        {
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
        }
        if (hex[i] == '2')
        {
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
        }
        if (hex[i] == '3')
        {
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
        }
        if (hex[i] == '4')
        {
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
        }
        else if (hex[i] == '5')
        {
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
        }
        else if (hex[i] == '6')
        {
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
        }
        else if (hex[i] == '7')
        {
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
        }
        else if (hex[i] == '8')
        {
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
        }
        else if (hex[i] == '9')
        {
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
        }
        else if (hex[i] == 'a')
        {
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
        }
        else if (hex[i] == 'b')
        {
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
        }
        else if (hex[i] == 'c')
        {
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
            res[k] = '0';
            k++;
        }
        else if (hex[i] == 'd')
        {
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
            res[k] = '1';
            k++;
        }
        else if (hex[i] == 'e')
        {
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
            res[k] = '0';
            k++;
        }
        else if (hex[i] == 'f')
        {
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
            res[k] = '1';
            k++;
        }
    }
}

void R_Format(char *res)
{
    // funct7 = 0x00
    if (res[0] == '0' && res[1] == '0' && res[2] == '0' && res[3] == '0' && res[4] == '0' && res[5] == '0' && res[6] == '0') // if funct7 = 0000000
    {
        if (res[17] == '0' && res[18] == '0' && res[19] == '0')
        {
            cout << "add ";
        }
        else if (res[17] == '0' && res[18] == '0' && res[19] == '1')
        {
            cout << "sll ";
        }
        else if (res[17] == '0' && res[18] == '1' && res[19] == '0')
        {
            cout << "slt ";
        }
        else if (res[17] == '0' && res[18] == '1' && res[19] == '1')
        {
            cout << "sltu ";
        }
        else if (res[17] == '1' && res[18] == '0' && res[19] == '0')
        {
            cout << "xor ";
        }
        else if (res[17] == '1' && res[18] == '0' && res[19] == '1')
        {
            cout << "srl ";
        }
        else if (res[17] == '1' && res[18] == '1' && res[19] == '0')
        {
            cout << "or ";
        }
        else if (res[17] == '1' && res[18] == '1' && res[19] == '1')
        {
            cout << "and ";
        }
    }
    else
    {
        if (res[17] == '0' && res[18] == '0' && res[19] == '0')
        {
            cout << "sub ";
        }
        else if (res[17] == '1' && res[18] == '0' && res[19] == '1')
        {
            cout << "sra ";
        }
    }
    // rd
    cout << "x";
    int sum1 = 0;
    for (int i = 24; i >= 20; i--)
    {
        int x = res[i] - '0';
        sum1 = sum1 + x * pow(2, 24 - i);
    }
    cout << sum1 << ", ";

    // rs1
    cout << "x";
    int sum = 0;
    for (int i = 16; i >= 12; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 16 - i);
    }
    cout << sum << ", ";

    // rs2
    cout << "x";
    sum = 0;
    for (int i = 11; i >= 7; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 11 - i);
    }
    cout << sum << endl;
}

void I_Format_1(char *res)
{
    if (res[17] == '0' && res[18] == '0' && res[19] == '0')
    {
        cout << "addi ";
    }
    else if (res[17] == '0' && res[18] == '0' && res[19] == '1')
    {
        cout << "slli ";
    }
    else if (res[17] == '0' && res[18] == '1' && res[19] == '0')
    {
        cout << "slti ";
    }
    else if (res[17] == '0' && res[18] == '1' && res[19] == '1')
    {
        cout << "sltui ";
    }
    else if (res[17] == '1' && res[18] == '0' && res[19] == '0')
    {
        cout << "xori ";
    }
    // ***************************
    else if (res[17] == '1' && res[18] == '0' && res[19] == '1')
    {
        int imm = 0;
        for (int i = 6; i >= 0; i--)
        {
            int x = res[i] - '0';
            imm = imm + x * pow(2, 6 - i);
        }
        if(imm == 0)
        cout << "srli ";
        else if(imm == 32)
        cout<<"srai ";
    }
    // ***************************
    else if (res[17] == '1' && res[18] == '1' && res[19] == '0')
    {
        cout << "ori ";
    }
    else if (res[17] == '1' && res[18] == '1' && res[19] == '1')
    {
        cout << "andi ";
    }
    // rd
    cout << "x";
    int sum1 = 0;
    for (int i = 24; i >= 20; i--)
    {
        int x = res[i] - '0';
        sum1 = sum1 + x * pow(2, 24 - i);
    }
    cout << sum1 << ", ";

    // rs1
    cout << "x";
    int sum = 0;
    for (int i = 16; i >= 12; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 16 - i);
    }
    cout << sum << ", ";

    // imm
    sum = 0;
    for (int i = 11; i >= 0; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 11 - i);
    }
    cout << sum << endl;
}

void I_Format_2(char *res)
{
    if (res[17] == '0' && res[18] == '0' && res[19] == '0')
    {
        cout << "lb ";
    }
    else if (res[17] == '0' && res[18] == '0' && res[19] == '1')
    {
        cout << "lh ";
    }
    else if (res[17] == '0' && res[18] == '1' && res[19] == '0')
    {
        cout << "lw ";
    }
    else if (res[17] == '0' && res[18] == '1' && res[19] == '1')
    {
        cout << "ld ";
    }
    else if (res[17] == '1' && res[18] == '0' && res[19] == '0')
    {
        cout << "lbu ";
    }
    // ***************************
    else if (res[17] == '1' && res[18] == '0' && res[19] == '1')
    {
        cout<< "lhu ";
    }
    // ***************************
    else if (res[17] == '1' && res[18] == '1' && res[19] == '0')
    {
        cout << "lwu ";
    }
    // rd
    cout << "x";
    int sum1 = 0;
    for (int i = 24; i >= 20; i--)
    {
        int x = res[i] - '0';
        sum1 = sum1 + x * pow(2, 24 - i);
    }
    cout << sum1 << ", ";

    // imm
    int sum = 0;
    for (int i = 11; i >= 0; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 11 - i);
    }
    cout << sum <<"(";  

    // rs1
    cout << "x";
    sum = 0;
    for (int i = 16; i >= 12; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 16 - i);
    }
    cout << sum <<")"<<endl; 
}

void S_Format(char *res)
{
        if (res[17] == '0' && res[18] == '0' && res[19] == '0')
        {
            cout << "sb ";
        }
        else if (res[17] == '0' && res[18] == '0' && res[19] == '1')
        {
            cout << "sh ";
        }
        else if (res[17] == '0' && res[18] == '1' && res[19] == '0')
        {
            cout << "sw ";
        }
        else if (res[17] == '0' && res[18] == '1' && res[19] == '1')
        {
            cout << "sd ";
        }
    // rs2
    int sum = 0;
    cout << "x";
    for (int i = 11; i >= 7; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 11 - i);
    }
    cout << sum <<", ";

    // imm
    int sum1 = 0;
    int i;
    for (i = 24; i >= 20; i--)
    {
        int x = res[i] - '0';
        sum1 = sum1 + x * pow(2, 24 - i);
    }  
    int sum2 = 0;
    for (int i = 6; i >= 0; i--)
    {
        int x = res[i] - '0';
        sum2 = sum2 + x * pow(2, 11 - i);
    }    
    sum = sum1 + sum2;
    cout<<sum;

    // rs1
    sum = 0;
    cout << "(x";
    for (int i = 16; i >= 12; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 16 - i);
    }
    cout << sum<<") "<<endl;
}

int B_Format(char *res)
{
       if (res[17] == '0' && res[18] == '0' && res[19] == '0')
        {
            cout << "beq ";
        }
        else if (res[17] == '0' && res[18] == '0' && res[19] == '1')
        {
            cout << "bne ";
        }
        else if (res[17] == '1' && res[18] == '0' && res[19] == '0')
        {
            cout << "blt ";
        }
        else if (res[17] == '1' && res[18] == '0' && res[19] == '1')
        {
            cout << "bge ";
        }
        else if (res[17] == '1' && res[18] == '1' && res[19] == '0')
        {
            cout << "bltu ";
        }
        else if (res[17] == '1' && res[18] == '1' && res[19] == '1')
        {
            cout << "bgeu ";
        }

    // rs1
    int sum = 0;
    cout << "x";
    for (int i = 16; i >= 12; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 16 - i);
    }
    cout << sum<<", ";   

    // rs2
     sum = 0;
    cout << "x";
    for (int i = 11; i >= 7; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 11 - i);
    }
    cout << sum <<", ";

    // // imm
    int sum1 = 0;
    int i;
    for (i = 23; i >= 20; i--)
    {
        int x = res[i] - '0';
        sum1 = sum1 + x * pow(2, 23 - i);
    }  
    int sum2 = 0;
    for (int i = 6; i >= 1; i--)
    {
        int x = res[i] - '0';
        sum2 = sum2 + x * pow(2, 10 - i);
    }    
    int x = res[24] - '0';
    int sum3 = x * pow(2, 10);    
    x = res[0] - '0';
    int sum4 = x * pow(2, 11);
    sum = sum1 + sum2 + sum3 + sum4;
    sum = sum * 2;
    cout<<"L1 "<<endl;
    return sum;
}

int J_Format(char *res)
{
    cout<< "jal ";
    // rd
    cout << "x";
    int sum1 = 0;
    for (int i = 24; i >= 20; i--)
    {
        int x = res[i] - '0';
        sum1 = sum1 + x * pow(2, 24 - i);
    }
    cout << sum1 << ", ";  

    sum1 = 0;
    for (int i = 10; i >= 1; i--)
    {
        int x = res[i] - '0';
        sum1 = sum1 + x * pow(2, 10 - i);
    } 
    int sum2 = 0;
    for (int i = 19; i >= 12; i--)
    {
        int x = res[i] - '0';
        sum1 = sum1 + x * pow(2, 29 - i);
    } 
    int sum3 = (res[11] - '0') * pow(2, 18);
    int sum4 = (res[0] - '0') * pow(2, 19);
    int sum = sum1 + sum2 + sum3 + sum4;
    sum = sum * 2;
    cout<<"L1 "<<endl;
    return sum;
}

void I3_Format(char *res)
{
    cout<<"jalr ";
    // rd
    cout << "x";
    int sum1 = 0;
    for (int i = 24; i >= 20; i--)
    {
        int x = res[i] - '0';
        sum1 = sum1 + x * pow(2, 24 - i);
    }
    cout << sum1 << ", ";

    // imm
    int sum = 0;
    for (int i = 11; i >= 0; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 11 - i);
    }
    cout << sum <<"(";  

    // rs1
    cout << "x";
    sum = 0;
    for (int i = 16; i >= 12; i--)
    {
        int x = res[i] - '0';
        sum = sum + x * pow(2, 16 - i);
    }
    cout << sum <<")"<<endl;     
}

void U_Format_1(char *res, char *hex)
{
    cout<<"lui ";
    //rd
    cout << "x";
    int sum1 = 0;
    for (int i = 24; i >= 20; i--)
    {
        int x = res[i] - '0';
        sum1 = sum1 + x * pow(2, 24 - i);
    }
    cout << sum1 << ", 0x";    
    for (int i = 0; i < 5; i++)
    {
        cout<<hex[i];
    } 
    cout<<endl;
}

void U_Format_2(char *res, char *hex)
{
    cout<<"auipc ";
    //rd
    cout << "x";
    int sum1 = 0;
    for (int i = 24; i >= 20; i--)
    {
        int x = res[i] - '0';
        sum1 = sum1 + x * pow(2, 24 - i);
    }
    cout << sum1 << ", 0x";    
    for (int i = 0; i < 5; i++)
    {
        cout<<hex[i];
    } 
    cout<<endl;
}

int main()
{ 
    /* count1, pcB are for Branch instruction */
    int count1 = INT_MAX;
    int pcB = INT_MAX;

    /* count2, pcJ are for J_Type */
    int count2 = INT_MAX;
    int pcJ = INT_MAX;
    int i = 0;
    char hex[100];
    char res[100];
    for (int i = 0; i < 6; i++)
    {
        cin >> hex;
        ConvertBinary(hex, res);
    // cout<<"hello"<<endl;
        
    // for (int i = 0; res[i] != '\0'; i++)
    // {
    //     cout << res[i];
    //     count++;
    // }
    // cout<<endl;
    // cout<<"hi"<<endl;
    for (int i = 0; res[i] != '\0'; i++)
    {    
        int j = 25;
        /* checking the conditions wheather to branch or not */
        if(count1 * 4 == pcB || count2 * 4 == pcJ)
        {
            cout<<"L1: ";
            /* againg initializing to normal */
            count1 = INT_MAX;
            count2 = INT_MAX;
            pcB = INT_MAX;
            pcJ = INT_MAX;
        }
        
        if(res[j] == '1' && res[j + 1] == '1' && res[j + 2] == '0' && res[j + 3] == '0' && res[j + 4] == '0' && res[j + 5] == '1' && res[j + 6] == '1')
        {
            count1 = 0;
            pcB = B_Format(res);
            break;
        }
        else if(res[j] == '1' && res[j + 1] == '1' && res[j + 2] == '0' && res[j + 3] == '1' && res[j + 4] == '1' && res[j + 5] == '1' && res[j + 6] == '1')
        {
            count2 = 0;
            pcJ = J_Format(res);
            break;
        }        
        else if (res[j] == '0' && res[j + 1] == '1' && res[j + 2] == '1' && res[j + 3] == '0' && res[j + 4] == '0' && res[j + 5] == '1' && res[j + 6] == '1')
        {
            R_Format(res);
            break;
        }
        else if (res[j] == '0' && res[j + 1] == '0' && res[j + 2] == '1' && res[j + 3] == '0' && res[j + 4] == '0' && res[j + 5] == '1' && res[j + 6] == '1')
        {
            I_Format_1(res);
            break;
        }
        else if(res[j] == '0' && res[j + 1] == '0' && res[j + 2] == '0' && res[j + 3] == '0' && res[j + 4] == '0' && res[j + 5] == '1' && res[j + 6] == '1')
        {
            I_Format_2(res);
            break;
        }
        else if(res[j] == '0' && res[j + 1] == '1' && res[j + 2] == '0' && res[j + 3] == '0' && res[j + 4] == '0' && res[j + 5] == '1' && res[j + 6] == '1')
        {
            S_Format(res);
            break;
        }
        else if(res[j] == '1' && res[j + 1] == '1' && res[j + 2] == '0' && res[j + 3] == '0' && res[j + 4] == '1' && res[j + 5] == '1' && res[j + 6] == '1')
        {
            I3_Format(res);
            break;
        }
        else if(res[j] == '0' && res[j + 1] == '1' && res[j + 2] == '1' && res[j + 3] == '0' && res[j + 4] == '1' && res[j + 5] == '1' && res[j + 6] == '1')
        {
            U_Format_1(res, hex);
            break;
        }
        else if(res[j] == '0' && res[j + 1] == '0' && res[j + 2] == '1' && res[j + 3] == '0' && res[j + 4] == '1' && res[j + 5] == '1' && res[j + 6] == '1')
        {
            U_Format_2(res, hex);
            break;
        } 
      } 
      count1++; 
      count2++;      
    }
    return 0;
}

/* 
1) For srai => bug
*/