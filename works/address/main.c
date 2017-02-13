#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
//#define NULL 0
#define LEN sizeof(struct address_list)
int n;
struct address_list
{
	char name[30];     //名字
	char work[30];     //职业
	char handset[30];  //手机
	char email[30];    //电子邮件
	char address[30];  //通讯地址
	struct address_list *next;
};
struct address_list* insert_txl(struct address_list *head);
struct address_list *search(struct address_list *head);
struct address_list *shifang(struct address_list *head); // 释放内存函数声明
//创建函数，不带头结点的链表
struct address_list *creat(void)
{
	struct address_list *head,*p1,*p2;
	char name[20];
	n=0;
	p1=(struct address_list *)malloc(LEN);
	p2=p1;   //强制内存转换
	printf("请输入通讯录的内容!\n姓名输入为 0 时表示创建完毕!\n");
	printf("请输入姓名:");
	gets(name);
	if(strcmp(name,"0")!=0)
	{
		strcpy(p1->name,name);
		printf("请输入职业:");     gets(p1->work);
		printf("请输入手机:");     gets(p1->handset);
		printf("请输入电子邮件:"); gets(p1->email);
		printf("请输入通讯地址:");  gets(p1->address);
		head=NULL;
		while(1)
		{
			n=n+1;   //记录通讯录人数个数
			if(n==1)
				head=p1;
			else
				p2->next=p1;
			p2=p1;
			printf("请输入姓名:");
			gets(name);
			if(strcmp(name,"0")==0)
			{
				break;
			}
			else
			{
				p1=(struct address_list *)malloc(LEN);
				strcpy(p1->name,name);
				printf("请输入职业:"); gets(p1->work);
				printf("请输入手机:"); gets(p1->handset);
				printf("请输入电子邮件:"); gets(p1->email);
				printf("请输入通讯地址:");  gets(p1->address);
			}
		}
		p2->next=NULL;
		return head;
	}
	else
		return 0;
}
//输出函数
void print(struct address_list *head)
{
	struct address_list *p;
	if(head!=NULL)
	{
		p=head;
		printf("本通讯录现在共有%d人:\n",n);
		printf("---姓名-------职业--------手机-------Email-------通讯地址\n");
		printf("==================================\n");
		do
		{
			printf("== %s",p->name); printf("       ");
			printf("%s",p->work); printf("       ");
			printf("%s",p->handset); printf("       ");
			printf("%s",p->email); printf("       ");
			printf("%s",p->address); printf("       \n");
			p=p->next;
		}while(p!=NULL);
		printf("==================================\n");
	}
	else
		printf("通讯录为空,无法输出!\n");
}
//增加函数
struct address_list *insert(struct address_list *head)
{
	struct address_list *p0,*p1,*p2;
	char name[20];
	p1=head;
	printf("请输入增加的内容:\n");
	printf("请输入姓名:"); gets(name);
	if(strcmp(name,"0")==0)
	{
		printf("姓名不能为0,增加失败!\n");
		return(head);
	}
	else
	{
		p0=(struct address_list *)malloc(LEN);
		strcpy(p0->name,name);
		printf("请输入职业:"); gets(p0->work);
		printf("请输入手机:"); gets(p0->handset);
		printf("请输入电子邮件:"); gets(p0->email);
		printf("请输入通讯地址:");  gets(p0->address);
		n=n+1;
		if(head==NULL)
		{
			head=p0;
			p0->next=NULL;
			return head;
		}
		else
		{
			while(strcmp(p0->name,p1->name)>0&&(p1->next!=NULL))
			{
				p2=p1;
				p1=p1->next;
			}
			if(strcmp(p0->name,p1->name)<0 || strcmp(p0->name,p1->name)==0)
			{
				if(head==p1)
				{
					head=p0;
				}
				else
				{
					p2->next=p0;
				}
				p0->next=p1;
			}
			else
			{
				p1->next=p0;
				p0->next=NULL;
			}
			return head;
		}
	}
}
struct address_list* delete_txl(struct address_list *head)
{
	struct address_list *p,*q;
	char name[30];
	if(head==NULL)
	{
		printf("通讯录为空,无法显示!\n");
		return head;
	}
	p=head;
	printf("请输入需要删除的人的姓名:");
	gets(name);
	if(strcmp(head->name,name)==0)
	{
		head=head->next;
		free(p);
		printf("删除操作成功！\n");
		return head;
	}
	else
	{
		q=head,p=head->next;
		while(p!=NULL)
		{
			if(strcmp(p->name,name)==0)
			{
				q->next=p->next;
				free(p);
				printf("删除操作成功！\n");
				return head;
			}
			p=p->next;
			q=q->next;
		}
	}
	return head;
}

struct address_list* modify_txl(struct address_list *head)
{
	struct address_list *p,*q;
	char name[30];
	if(head==NULL)
	{
		printf("通讯录为空,无法显示!\n");
		return head;
	}
	p=head;
	printf("请输入需要修改的人的姓名:");
	gets(name);
	if(strcmp(head->name,name)==0)
	{
		head=head->next;
		free(p);
		head=insert_txl(head);
		return head;
	}
	else
	{
		q=head,p=head->next;
		while(p!=NULL)
		{
			if(strcmp(p->name,name)==0)
			{
				q->next=p->next;
				free(p);
				head=insert_txl(head);
				return head;
			}
			p=p->next;
			q=q->next;
		}
	}
	return head;
}

struct address_list* insert_txl(struct address_list *head)
{
	struct address_list *p0,*p1,*p2;
	char name[20];
	p1=head;
	printf("请输入姓名:"); gets(name);
	if(strcmp(name,"0")==0)
	{
		printf("姓名不能为0,增加失败!\n");
		return(head);
	}
	else
	{
		p0=(struct address_list *)malloc(LEN);
		strcpy(p0->name,name);
		printf("请输入职业:"); gets(p0->work);
		printf("请输入手机:"); gets(p0->handset);
		printf("请输入电子邮件:"); gets(p0->email);
		printf("请输入通讯地址:");  gets(p0->address);
		n=n+1;
		if(head==NULL)
		{
			head=p0;
			p0->next=NULL;
			return head;
		}
		else
		{
			while(strcmp(p0->name,p1->name)>0&&(p1->next!=NULL))
			{
				p2=p1;
				p1=p1->next;
			}
			if(strcmp(p0->name,p1->name)<0 || strcmp(p0->name,p1->name)==0)
			{
				if(head==p1)
				{
					head=p0;
				}
				else
				{
					p2->next=p0;
				}
				p0->next=p1;
			}
			else
			{
				p1->next=p0;
				p0->next=NULL;
			}
			return head;
		}
	}
}
//显示函数
struct address_list *display(struct address_list *head)
{
	struct address_list *p1,*p2;
	char name[30];
	int m;
	if(head==NULL)
	{
		printf("通讯录为空,无法显示!\n");
		return head;
	}
	p1=head;
	m=0;
	printf("请输入需要显示人的姓名:");
	gets(name);
	while(p1!=NULL)
	{
		while((strcmp(p1->name,name))!=0 && p1->next!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}
		if(strcmp(p1->name,name)==0)
		{
			m++;
			printf("%s的通讯内容如下:\n",name);
			printf("---姓名--------职业--------手机-------Email------通讯地址\n");
			printf("==================================\n");
			printf("== %s",p1->name);printf("       ");
			printf("%s",p1->work);printf("       ");
			printf("%s",p1->handset);printf("       ");
			printf("%s",p1->email);printf("       ");
			printf("%s",p1->address); printf("       \n");
			printf("==================================\n");
		}
		p1=p1->next;
	}
	if(m==0)
	{
		printf("此人未在本通讯录中!\n");
	}
	return(head);
}

//排序函数
struct address_list *paixu(struct address_list *head)
{
	struct address_list *p1,*p2;
	int i,j;
	struct address_list1
	{
		char name[30];
		char work[30];
		char handset[30];
		char email[30];
		char address[30];
	};
	struct address_list1 px[200];
	struct address_list1 temp;
	if(head==NULL)
	{
		printf("通讯录为空,无法排序!\n");
		return(head);
	}
	p1=head;
	for(i=0;i<n,p1!=NULL;i++)
	{
		strcpy(px[i].name,p1->name);
		strcpy(px[i].work,p1->work);
		strcpy(px[i].handset,p1->handset);
		strcpy(px[i].email,p1->email);
		strcpy(px[i].address,p1->address);
		p2=p1;
		p1=p1->next;
	}
	head=shifang(head);
	for(j=0;j<n-1;j++)
	{
		for(i=j+1;i<n;i++)
		{
			if(strcmp(px[i].name,px[j].name)<0)
			{
				temp=px[i];
				px[i]=px[j];
				px[j]=temp;
			}
		}
	}
	p1=(struct address_list *)malloc(LEN);
	p2=p1;
	strcpy(p1->name,px[0].name);
	strcpy(p1->work,px[0].work);
	strcpy(p1->handset,px[0].handset);
	strcpy(p1->email,px[0].email);
	strcpy(p1->address,px[0].address);

	head=p1;
	for(i=1;i<n;i++)
	{
		p1=(struct address_list *)malloc(LEN);
		strcpy(p1->name,px[i].name);
		strcpy(p1->work,px[i].work);
		strcpy(p1->handset,px[i].handset);
		strcpy(p1->email,px[i].email);
		strcpy(p1->address,px[i].address);
		p2->next=p1;
		p2=p1;
	}
	p2->next=NULL;
	printf("按姓名排序后为:\n");
	print(head);
	return(head);
}
//姓名查找函数
struct address_list *search_name(struct address_list *head)
{
	struct address_list *p1,*p2;
	int m;
	char name[30];
	if(head==NULL)
	{
		printf("通讯录为空,无法分类查找!\n");
		return(head);
	}
	p1=head;
	printf("********************\n");
	printf("**  请输入需要查找的姓名  **\n");
	printf("********************\n");
	m=0;
	gets(name);
	while(p1!=NULL)
	{
		while(strcmp(p1->name,name)!=0&&p1->next!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}
		if(strcmp(p1->name,name)==0)
		{
			m++;
			printf("你查找的内容是:\n");
			printf("+++++++++++++++++++++++++++++++++++\n");
			printf("++ %s        %s       %s       %s        %s\n",p1->name,p1->work,p1->handset,p1->email,p1->address);
			printf("+++++++++++++++++++++++++++++++++++\n");
		}
		p1=p1->next;

		if(m==0)
		{
			printf("此人未在本通讯录中!\n");
		}
		break;
	}

	return(head);
}
//电话查找函数
struct address_list *search_handset(struct address_list *head)
{
	struct address_list *p1,*p2;
	int m;
	char handset[30];
	if(head==NULL)
	{
		printf("通讯录为空,无法分类查找!\n");
		return(head);
	}
	p1=head;
	printf("********************\n");
	printf("**  请输入需要查找的姓名  **\n");
	printf("********************\n");
	m=0;
	gets(handset);
	while(p1!=NULL)
	{
		while(strcmp(p1->handset,handset)!=0&&p1->next!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}
		if(strcmp(p1->handset,handset)==0)
		{
			m++;
			printf("你查找的内容是:\n");
			printf("+++++++++++++++++++++++++++++++++++\n");
			printf("++ %s        %s       %s       %s        %s\n",p1->name,p1->work,p1->handset,p1->email,p1->address);
			printf("+++++++++++++++++++++++++++++++++++\n");
		}
		p1=p1->next;

		if(m==0)
		{
			printf("此人未在本通讯录中!\n");
		}
		break;
	}

	return(head);
}
//email查找函数
struct address_list *search_email(struct address_list *head)
{
	struct address_list *p1,*p2;
	int m;
	char email[30];
	if(head==NULL)
	{
		printf("通讯录为空,无法分类查找!\n");
		return(head);
	}
	p1=head;
	printf("********************\n");
	printf("**  请输入需要查找的姓名  **\n");
	printf("********************\n");
	m=0;
	gets(email);
	while(p1!=NULL)
	{
		while(strcmp(p1->email,email)!=0&&p1->next!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}
		if(strcmp(p1->email,email)==0)
		{
			m++;
			printf("你查找的内容是:\n");
			printf("+++++++++++++++++++++++++++++++++++\n");
			printf("++ %s        %s       %s       %s        %s\n",p1->name,p1->work,p1->handset,p1->email,p1->address);
			printf("+++++++++++++++++++++++++++++++++++\n");
		}
		p1=p1->next;

		if(m==0)
		{
			printf("此人未在本通讯录中!\n");
		}
		break;
	}

	return(head);
}
//释放内存函数
struct address_list *shifang(struct address_list *head)
{
	struct address_list *p1;
	while(head!=NULL)
	{
		p1=head;
		head=head->next;
		free(p1);
	}
	return(head);
}

//文件写入函数
void save(struct address_list *head)
{
	FILE *fp;
	struct address_list *p1;
	char tong[30];
	if(head==NULL)
	{
		printf("通讯录为空,无法存储!\n");
		return;
	}
	printf("请输入保存后的文件名:");
	gets(tong);
	strcat(tong,".txt");
	fp=fopen(tong,"w");
	if(fp==NULL)
	{
		printf("cannot open file\n");
		return;
	}
	p1=head;
	fprintf(fp,"姓名    职业      手机     Email     通讯地址\n");
	for(;p1!=NULL;)
	{
		fprintf(fp,"%s       %s       %s        %s       %s\n",p1->name,p1->work,p1->handset,p1->email,p1->address);
		p1=p1->next;
	}
	printf("保存完毕!\n");
	fclose(fp);
}

//文件读出函数
struct address_list *load(struct address_list *head)
{
	FILE *fp;
	char tong[30];
	struct address_list *p1,*p2;
	printf("请输入要输出的文件名:");
	gets(tong);
	strcat(tong,".txt");
	fp=fopen(tong,"r");
	if(fp==NULL)
	{
		printf("此通讯录名不存在,无法输出!\n");
		return(head);
	}
	else
	{
		head=shifang(head);
	}
	p1=(struct address_list *)malloc(LEN);
	fscanf(fp,"%s%s%s%s%s",&p1->name,&p1->work,&p1->handset,&p1->email,&p1->address);
	if(feof(fp)!=0)
	{
		printf("文件为空,无法打开!\n");
		return(head);
	}
	else
	{
		rewind(fp);
		p2=p1;
		head=p1;
		n=0;
		while(feof(fp)==0)
		{
			fscanf(fp,"%s%s%s%s%s",&p1->name,&p1->work,&p1->handset,&p1->email,&p1->address);
			if(feof(fp)!=0)
				break;
			p2->next=p1;
			p2=p1;
			p1=(struct address_list *)malloc(LEN);
			n=n+1;
		}
		p2->next=NULL;
		p1=head;
		head=head->next;
		n=n-1;
		free(p1);
		print(head);
		printf("打开完毕!\n");
		return(head);
	}
	fclose(fp);
}

//综合操作函数
struct address_list *menu(struct address_list *head)
{
	char num[10];
	while(1)
	{
		printf("*****************************\n");
		printf("****     1 查找          ****\n");
		printf("****     2 单个显示      ****\n");
		printf("****     3 增加          ****\n");
		printf("****     4 删除          ****\n");
		printf("****     5 修改          ****\n");
		printf("****     6 退出          ****\n");
		printf("*****************************\n");
		printf("请输入您选择的操作:");
		gets(num);
		switch(*num)
		{
		case '1':
			{
				head=search(head);                          //姓名查找
				print(head);
			}
			break;
		case '2':
			{
				head=display(head);                          //显示
			}
			break;
		case '3':
			{
				head=insert(head);                           //增加
				print(head);
			}
			break;
        case '4':
			{
				head=delete_txl(head);                           //删除
				print(head);
			}
        case '5':
			{
				head=modify_txl(head);                           //修改
				print(head);
			}
			break;
		case '6':
			return head;
		default:
			printf("操作错误，此项不存在!\n");
			break;
		}
		if(strcmp(num,"6")==0)
			break;
	}
	return head;
}

//查找
struct address_list *search(struct address_list *head)
{
	char num[10];
	while(1)
	{
		printf("*****************************\n");
		printf("****     1 姓名查找      ****\n");
		printf("****     2 电话查找      ****\n");
		printf("****     3 email查找     ****\n");
		printf("****     4 退出          ****\n");
		printf("*****************************\n");
		printf("请输入您选择的操作:");
		gets(num);
		switch(*num)
		{
		case '1':
			{
				head=search_name(head);                          //姓名查找
			}
			break;
		case '2':
			{
				head=search_handset(head);                          //电话查找
			}
			break;
		case '3':
			{
				head=search_email(head);                          //email查找
			}
			break;
		case '4':
			return head;
		default:
			printf("操作错误，此项不存在!\n");
			break;
		}
		if(strcmp(num,"4")==0)
			break;
	}
	return head;
}

char* get_password(void){
    FILE *fp;
    static char password[20];
    if((fp=fopen("password","r+"))==NULL)
    {
        strcpy(password, "root");
    }
    else
        fscanf(fp,"%s",&password);
    fclose(fp);
    return password;
}
void change_password(void){
    FILE *fp;
    char password[20];
    char old_password[20];
    char new_password1[20];
    char new_password2[20];
    if((fp=fopen("password","r+"))==NULL)
    {
        strcpy(password, "root");
    }
    else
        fscanf(fp,"%s",&password);
    fclose(fp);
    printf("请输入原始密码：");
    while(strcmp(gets(old_password),password)!=0){
        printf("密码错误，请重新输入：");
    }
    while(1)
    {
        printf("请输入新密码：");
        gets(new_password1);
        printf("请再次输入新密码：");
        gets(new_password2);
        if(strcmp(new_password1,new_password2)!=0)
        {
            printf("密码不一致\n");
        }
        else break;
    }
    fp=fopen("password","w+");
    fprintf(fp,new_password1);
    fclose(fp);
}
//主函数
int main(int argc,char* argv)
{
	struct address_list *head=NULL;
	char num[10];
	char* password;
	char inpass[20];
	password=get_password();
	printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
	printf("*=*               程序说明                *=*\n");
	printf("*=*    请及时保存创建完毕的通讯录内容!    *=*\n");
	printf("*=*  如果你从未设置过密码，则密码为root   *=*\n");
	printf("*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
	printf("请输入密码：");
	while(1)
	{
	    gets(inpass);
	    if(strcmp(inpass,password)==0){
            break;
	    }
	    printf("密码错误，请重新输入密码：");
    }
	while(1)
	{
		printf("*******************************\n");
		printf("****     1 创建通讯录      ****\n");
		printf("****     2 按名字排序      ****\n");
		printf("****     3 综合操作        ****\n");
		printf("****     4 保存            ****\n");
		printf("****     5 打开            ****\n");
		printf("****     6 删除            ****\n");
		printf("****     7 更改密码        ****\n");
		printf("****     8 退出            ****\n");
		printf("*******************************\n");
		printf("请输入您选择的操作:");
		gets(num);
		switch(*num)
		{
		case '1':
			{
				if(head==NULL)
				{
					head=creat();                                //创建
					print(head);
				}
				else
				{
					head=shifang(head);
					head=creat();                                //重新创建
					print(head);
				}
			}
			break;
		case '2':
			{
				head=paixu(head);                               //排序
			}
			break;
		case '3':
			{
				head=menu(head);                              //综合操作
			}
			break;
		case '4':
			{
				save(head);                                   //文件保存
				print(head);
			}
			break;
		case '5':
			{
				head=load(head);                              //文件输出
			}
			break;
		case '6':
			{
				head=delete_txl(head);                           //删除
				print(head);
			}
			break;
		case '7':
            {
                change_password();
                print(head);
            }
			break;
        case '8':
			head=shifang(head);
			break;
		default:
			printf("操作错误，此项不存在!\n");
			break;
		}
		if(strcmp(num,"8")==0)
			break;
	}
	return 0;
}
