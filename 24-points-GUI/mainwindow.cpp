#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_2->setChecked(true);
    ui->label->setText("?");
    ui->label_2->setText("?");
    ui->label_3->setText("?");
    ui->label_4->setText("?");
    ui->label_6->setText("");
    on_pushButton_3_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->label_6->clear();
    if(ui->radioButton->isChecked())
    {
        int cnt=0;
        while (cnt <= 9)
        {
            pro.cre();
            cnt = pro.count();
        }
        ui->label->setText(QString::number(pro.a));
        ui->label_2->setText(QString::number(pro.b));
        ui->label_3->setText(QString::number(pro.c));
        ui->label_4->setText(QString::number(pro.d));
    }
    if(ui->radioButton_2->isChecked())
    {
        int cnt=0;
        while (cnt > 9 || cnt < 4)
        {
            pro.cre();
            cnt = pro.count();
        }
        ui->label->setText(QString::number(pro.a));
        ui->label_2->setText(QString::number(pro.b));
        ui->label_3->setText(QString::number(pro.c));
        ui->label_4->setText(QString::number(pro.d));
    }
    if(ui->radioButton_3->isChecked())
    {
        int cnt=0;
        while (cnt > 4 || cnt == 0)
        {
            pro.cre();
            cnt = pro.count();
        }
        ui->label->setText(QString::number(pro.a));
        ui->label_2->setText(QString::number(pro.b));
        ui->label_3->setText(QString::number(pro.c));
        ui->label_4->setText(QString::number(pro.d));
    }
    if(ui->radioButton_4->isChecked())
    {
        int cnt=0;
        while (cnt == 0)
        {
            pro.cre();
            cnt = pro.count();
        }
        ui->label->setText(QString::number(pro.a));
        ui->label_2->setText(QString::number(pro.b));
        ui->label_3->setText(QString::number(pro.c));
        ui->label_4->setText(QString::number(pro.d));
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label_6->setText(QString::fromStdString(pro.ansStr+" = 24"));
}


void MainWindow::on_pushButton_clicked()
{
    string str=ui->lineEdit->text().toStdString();
    int len=str.length();
    if(len==0)
    {
        ui->label_6->setText("请输入非空表达式!");
        return;
    }
    bool flag=true;
    bool used[4]={false,false,false,false};
    for(int i=0;i<len;i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            int num=str[i]-'0';
            if(i!=len-1&&str[i+1]>='0'&&str[i+1]<='9')
            {
                num*=10;
                num+=str[i+1]-'0';
                i++;
            }
            if(num!=int(pro.a)&&num!=int(pro.b)&&num!=int(pro.c)&&num!=int(pro.d))
            {
                flag=false;
                break;
            }
            if(num==int(pro.a))
            {
                used[0]=true;
            }
            if(num==int(pro.b))
            {
                used[1]=true;
            }
            if(num==int(pro.c))
            {
                used[2]=true;
            }
            if(num==int(pro.d))
            {
                used[3]=true;
            }
        }
        else
        {
            if(str[i]!='+'&&str[i]!='-'&&str[i]!='*'&&str[i]!='/'&&str[i]!='('&&str[i]!=')')
            {
                flag=false;
                break;
            }
            if(str[i]=='(')
            {
                if(i==len-1)
                {
                    flag=false;
                    break;
                }
                if(i&&(str[i-1]>='0'&&str[i-1]<='9'))
                {
                    flag=false;
                    break;
                }
                if(!(str[i+1]>='0'&&str[i+1]<='9'))
                {
                    flag=false;
                    break;
                }
            }
            else if(str[i]==')')
            {
                if(!i)
                {
                    flag=false;
                    break;
                }
                if(!(str[i-1]>='0'&&str[i-1]<='9'))
                {
                    flag=false;
                    break;
                }
                if(i!=len-1&&!(str[i-1]>='0'&&str[i-1]<='9'))
                {
                    flag=false;
                    break;
                }
            }
            else
            {
                if(!i||i==len-1)
                {
                    flag=false;
                    break;
                }
                if(str[i-1]!=')'&&!(str[i-1]>='0'&&str[i-1]<='9'))
                {
                    flag=false;
                    break;
                }
                if(str[i+1]!='('&&!(str[i+1]>='0'&&str[i+1]<='9'))
                {
                    flag=false;
                    break;
                }
            }
        }
    }
    if(!flag)
    {
        ui->label_6->setText("请输入合法表达式!");
        return;
    }
    else if(!(used[0]&&used[1]&&used[2]&&used[3]))
    {
        ui->label_6->setText("请将数字全部使用!");
        return;
    }
    double ans=pro.exp(str);
    if(ans>23.99&&ans<24.01) ui->label_6->setText("正确!");
    else ui->label_6->setText("错误!");
}

