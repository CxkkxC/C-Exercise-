﻿#include<math.h>
#include<time.h>
#include <stdlib.h>
#include<conio.h>
#include<iomanip>
#include<iostream>
using namespace std;
// 加法
float Sum(float a, float b) {
  return a + b;
}
// 减法
float Sub(float a, float b) {
  return a - b;
}
// 乘法
float Mul(float a, float b) {
  return a * b;
}
// 除法
float Div(float a, float b) {
  return a / b;
}
// 开根号
float Gh(float b) {
  float a = 0;
  a = sqrt(b);
  return a;
}
// 解一元二次方程
void Set(float a, float b, float c) // Solve equations
{
  {
    float d;
    float x1, x2, e;            // 求解方程 ax^2+bx+c
    e = sqrt(d);
    cout << "根据判别式求解一元二次方程。(ax^2+bx+c)" << endl;
    cout << "请依次输入一元二次方程中的a,b,c,并按回车键结束。" << endl; // 提示用户输入方程a,b,c的值
    cout << "a=";
    cin >> a;                   // 键盘输入有效值a
    cout << "b=";
    cin >> b;                   // 键盘输入有效值b
    cout << "c=";
    cin >> c;                   // 键盘输入有效值c 
    cout << "此方程为:" << a << "x^2+" << b << "x+" << c << endl; // 显示用户输入的方程
    d = b * b - 4 * a * c;      // 判别式
    x1 = (-b + sqrt(d)) / (2 * a); // 解出x1
    x2 = (-b - sqrt(d)) / (2 * a); // 解出x2 
    if (d < 0)                  // 如果判别式小于0显示无解
      cout << "此方程无实根。" << endl;
    else                        // 如果判别式大于0就显示出解
    {
      cout << "大帅哥大声的告诉你此方程的解是:" << '\n' << "x1="
        << x1 << endl;
      cout << "x2=" << x2 << endl;
    }
  }
}
void Mot()                      // Matrix operation(矩阵运算)
{
  cout <<   "降阶法计算三阶四阶行列式，得出三阶转置丶伴随矩阵与逆矩阵。"
    << endl;
  while (1) {
    int i, j;
    cout << "请输入矩阵的行数和列数:\n"; /* 
                                                       cout<<'\n'<<"行数为:";
                                                       cin>>i;
                                                       cout<<"列数为:";
                                                       cin>>j; */
    while (cin >> i >> j) {
      if (i * j != 9 && i * j != 16 && i * j != 25) {
        cout <<
          "对不起，只能计算三四五阶行列式，你的输入有误！请重新输入行列数（3x3，4x4或者5x5）。"
          << endl;
      } else {
        break;
      }
    }
    int a, b;
    int **m = new int *[i];
    // int *m[i];
    // 预先定义一个指针数组m,用于保存i个一维数组的首地址。
    for (a = 0; a < i; a++)
      // 使用循环结构，为每行动态分配一个一维数组。
    {
      m[a] = new int[j];
      // 动态分配一维数组，元素个数应等于二维数组的列数j。
    }
    // 赋值过程
    for (a = 0; a < i; a++)
      for (b = 0; b < j; b++) {
        cout << "请输入数组a[" << a << "][" << b << "]的值:";
        cin >> m[a][b];
        cout << endl;
      }
    // 显示过程
    cout << "输入的这个矩阵为：" << endl;
    for (a = 0; a < i; a++)     // 行
    {
      for (b = 0; b < j; b++)   // 列
      {
        cout << m[a][b] << " ";
      }
      cout << endl;
    }
    /* 计算三阶四阶行列式，流沙法计算三阶行列式，按第三列展开计算四阶行列式 
     */
    // 这辈子都不会再写矩阵的代码了
    if (i * j == 9) {
      int a1, a2;
      // 根据矩阵运算方法写的
      float D = 0;
      a1 =
        m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] +
        m[0][2] * m[1][0] * m[2][1];
      a2 =
        m[0][2] * m[1][1] * m[2][0] + m[0][0] * m[1][2] * m[2][1] +
        m[0][1] * m[1][0] * m[2][2];
      D = a1 - a2;
      cout << "这个三阶行列式的值为：" << "|A|或者是D=" << D <<
        endl;
      int t[3][3];
      for (int n = 0; n < i; n++) {
        for (int M = 0; M < j; M++) {
          t[M][n] = m[n][M];
        }
      }
      cout << endl;
      cout << "这个转置后的矩阵A^T为：" << endl;
      for (int c = 0; c < j; c++) {
        for (int d = 0; d < i; d++) {
          cout << t[c][d] << " ";
        }
        cout << endl;
      }
      cout << "这个矩阵的伴随矩阵A*为：" << endl;
      float A11, A12, A13, A21, A22, A23, A31, A32, A33;
      A11 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
      A12 = -(m[1][0] * m[2][2] - m[1][2] * m[2][0]);
      A13 = m[1][0] * m[2][1] - m[1][1] * m[2][0];
      A21 = -(m[0][1] * m[2][2] - m[0][2] * m[2][1]);
      A22 = m[0][0] * m[2][2] - m[0][2] * m[2][0];
      A23 = -(m[0][0] * m[2][1] - m[0][1] * m[2][0]);
      A31 = m[0][1] * m[1][2] - m[0][2] * m[1][1];
      A32 = -(m[0][0] * m[1][2] - m[0][2] * m[1][0]);
      A33 = m[0][0] * m[1][1] - m[0][1] * m[1][0];
      m[0][0] = A11;
      m[0][1] = A21;
      m[0][2] = A31;
      m[1][0] = A12;
      m[1][1] = A22;
      m[1][2] = A32;
      m[2][0] = A13;
      m[2][1] = A23;
      m[2][2] = A33;
      for (int g = 0; g < 3; g++) {
        for (int s = 0; s < 3; s++) {
          cout << m[g][s] << " ";
        }
        cout << endl;
      }
      cout << endl;
      float A1 = 0, A2 = 0, A3 = 0, A4 = 0, A5 = 0, A6 = 0, A7 = 0, A8 =
        0, A9 = 0;
      A1 = 1 / D * A11;
      A2 = 1 / D * A21;
      A3 = 1 / D * A31;
      A4 = 1 / D * A12;
      A5 = 1 / D * A22;
      A6 = 1 / D * A32;
      A7 = 1 / D * A13;
      A8 = 1 / D * A23;
      A9 = 1 / D * A33;
      float o[3][3] = { {A1, A2, A3}, {A4, A5, A6}, {A7, A8, A9} };
      cout << "这个矩阵的逆矩阵A^-1为：" << endl;
      for (int w = 0; w < 3; w++) {
        for (int f = 0; f < 3; f++) {
          cout << setiosflags(ios::fixed) << setprecision(1);
          /* 需要保存的小数位数，头文件<iomanip> */
          cout << o[w][f] << " ";
        }
        cout << endl;
      }
      cout << endl;
    } else if (i * j == 16) {
      int A13, A23, A33, A43, D1 = 0;
      A13 =
        m[1][0] * m[2][1] * m[3][3] + m[1][1] * m[2][3] * m[3][0] +
        m[1][3] * m[2][0] * m[3][1] - m[1][3] * m[2][1] * m[3][0] -
        m[1][0] * m[2][3] * m[3][1] - m[1][1] * m[2][0] * m[3][3];
      A23 =
        -(m[0][0] * m[2][1] * m[3][3] + m[0][1] * m[2][3] * m[3][0] +
          m[0][3] * m[2][0] * m[3][1] - m[0][3] * m[2][1] * m[3][0] -
          m[0][0] * m[2][3] * m[3][1] - m[0][1] * m[2][0] * m[3][3]);
      A33 =
        m[0][0] * m[1][1] * m[3][3] + m[0][1] * m[1][3] * m[3][0] +
        m[0][3] * m[1][0] * m[3][1] - m[0][3] * m[1][1] * m[3][0] -
        m[0][0] * m[1][3] * m[3][1] - m[0][1] * m[1][0] * m[3][3];
      A43 =
        -(m[0][0] * m[1][1] * m[2][3] + m[0][1] * m[1][3] * m[2][0] +
          m[0][3] * m[1][0] * m[2][1] - m[0][3] * m[1][1] * m[2][0] -
          m[0][0] * m[1][3] * m[2][1] - m[0][1] * m[1][0] * m[2][3]);
      D1 =
        (m[0][2] * A13) + (m[1][2] * A23) + (m[2][2] * A33) + (m[3][2] * A43);
      cout << "这个四阶行列式的值为：" << "D =" << D1 << endl;
    }
    char Cxk;
    cout <<
      "如需继续计算请输入Y,不需要请输入N,大小写均可。" <<
      endl;
    cin >> Cxk;
    cout << endl;
    if (Cxk == 'Y' || Cxk == 'y') {
      continue;
    } else {
      break;
    }
  }
}
void EdLs()
// Equal difference series(等差数列)
// Lsometric series(等比数列)
{
  while (true) {
    int m;
    cout <<
      "\033[;32;m请问您是计算等差还是等比数列的前n项和？\n计算等差数列请输入数字1。\n计算等比数列请输入数字2。\n输入其它数字将跳出这个功能。\033[m"
      << endl;
    cin >> m;
    if (m == 1) {
      int N, sum = 0, d, m, a0;
      cout << "请输入等差数列的项数和公差d。" << endl;
      cout << "项数为:";
      cin >> N;
      cout << "请输入等差数列的首项a0=";
      cin >> a0;
      cout << "公差d为:";
      cin >> d;
      int *F = new int[N];      // 定义指针变量
      F[0] = a0;
      int n;
      for (n = 1; n < N; n++)
        F[n] = F[n - 1] + d;
      cout << "该数列为:";
      for (n = 0; n < N; n++) {
        cout << F[n] << " , ";
        if ((n + 1) % 10 == 0)
          cout << endl;
      }
      cout << "\n请输入需要求的前m项和的值,m=";
      cin >> m;
      for (n = 0; n < m; n++)
        sum += F[n];
      cout << "等差数列的和为:" << sum << endl;
      break;
    } else if (m == 2) {
      int M, sum = 0, q, p, a0;
      cout << "请输入等比数列的项数和公比q。" << endl;
      cout << "项数为:";
      cin >> M;
      cout << "请输入等比数列的首项a0=";
      cin >> a0;
      cout << "公比q为:";
      cin >> q;
      double *F = new double[M];
      F[0] = a0;
      int o;
      for (o = 1; o < M; o++)
        F[o] = F[o - 1] * q;
      cout << "该数列为:";
      for (o = 0; o < M; o++) {
        cout << F[o] << " , ";
        if ((o + 1) % 10 == 0)
          cout << endl;
      }
      cout << "\n请输入需要求的前p项和的值,p=";
      cin >> p;
      for (o = 0; o < p; o++)
        sum += F[o];
      cout << "等比数列的和为:" << sum << endl;
    }
    break;
  }
}
void Csz_game() {
  cout << "\033[;32;m游戏开始，祝您好运！\n";
  int Cs = 0, Nd;
  int Sz;
  srand((unsigned)time(NULL));
  Sz = rand() % 100 + 1;
  /* 系统在调用rand（）之前都会自动调用srand()，如果用户在rand()之前曾调用过srand()给参数seed指定了一个值，那么rand()就会将seed的值作为产生伪随机数的初始值；而如果用户在rand()前没有调用过srand()，那么系统默认将1作为伪随机数的初始值。如果给了一个定值，那么每次rand()产生的随机数序列都是一样的。 
     所以为了避免上述情况的发生我们通常用srand((time(0)))或者srand((time(NULL)))来产生种子。rand()是随机产生0－32767之间的数，%是取余数,rand()会回传一个乱数，rand()%100乱数会介于0~99之间，再+1会变成1~100之间，所以rand()%100+1 
     就是一个1~100之间的乱数 */
  while (true)                  // 大循环，整个游戏的循环
  {
    cout <<
      "请选择你需要挑战的难度\n输入1即为只能猜数一次\n输入2即为只能猜数两次\n以此类推。"
      << endl;
    cin >> Nd;
    cout << "系统已给出一个1～100的随机数字。\n您共有" <<Nd<<
      "次机会根据提示猜出这个数字。\n";
    int Jx, Jf = 0;
    int Csz;
    while (cout << "请输入您要猜的数字:\033[m",
           cin >> Csz)
      // 小循环，每输出一次提示，次数(Cs)加一，直到第七次跳出循环，游戏结束！积分(Jf)清零。
    {
      if (Csz > Sz + 20) {
        cout << "猜太大了！\n";
        Cs++;
      } else if (Csz > Sz + 15) {
        cout << "猜大了哦，还可以再小点！\n";
        Cs++;
      } else if (Csz > Sz + 10) {
        cout << "猜大了哦，还可以再小点点！\n";
        Cs++;
      } else if (Csz > Sz + 5) {
        cout << "猜大了哦，要不再小点点？\n";
        Cs++;
      } else if (Csz > Sz) {
        cout << "猜大了哦，应该还可以再小点点！\n";
        Cs++;
      } else if (Csz < Sz - 20) {
        cout << "猜太小了！\n";
        Cs++;
      } else if (Csz < Sz - 15) {
        cout << "猜小了哦，还可以再大点！\n";
        Cs++;
      } else if (Csz < Sz - 10) {
        cout << "猜小了哦，还可以再大点点！\n";
        Cs++;
      } else if (Csz < Sz - 5) {
        cout << "猜小了哦，要不再大点点？\n";
        Cs++;
      } else if (Csz < Sz) {
        cout << "猜小了哦，应该还可以再大点！\n";
        Cs++;
      } else if (Csz == Sz) {
        cout <<
          "\033[;32;m恭喜你，猜对了！\n奖你一个么么哒～(^з^)-☆\n";
        Jf++;
        cout << "您的积分为：" << Jf << endl;
        cout << "请您继续！\n\033[m";
        Cs = 0;
        srand((unsigned)time(NULL));
        Sz = rand() % 100 + 1;
      }
      if (Cs == Nd) {
        cout << Nd <<
          "次机会已用光！\n游戏结束！\n(ಥ_ಥ)\n您的游戏积分为:"
          << Jf << endl;
        cout << "正确答案是：" << Sz << endl;
        break;
      }
    }
    cout <<
      "\033[;31;m继续小游戏请输入数字 1 \n否则请输入其它数字退出游戏。\n\033[m";
    cin >> Jx;
    Jf = 0;
    Cs = 0;
    if (Jx == 1) {
      cout << "很好，请继续您的猜字游戏！\n";
      srand((unsigned)time(NULL));
      Sz = rand() % 100 + 1;
      continue;
    } else
      break;
  }
}
#define H 19 /*地图的高*/ 
#define W 50/*地图的宽*/ 
 int a, b, x, y, l = 0, n, i, j,Yes,N,J = 0;
int x1, y2;//食物坐标
char *head  , *tail  ,*tt , map[H][W];
char *belly[H * W]  , *food /* 食物 */ ;
char L, R, F, B;
	//方向
void start()
{
	for (i = 0; i != H; i++)
		for (j = 0; j != W; j++)
		{
			if ((j == 0))
				map[i][j] = '9';//左边高墙
				else if((j==W-1))
				map[i][j] = '9';//右边高墙
				else if((i==0))
				map[i][j]='5';//上地面
				else if((i==H-1))//下地面
				map[i][j]='5';
			else
				map[i][j] = '0';
		}						/*以上是初始化地图,地图数组的四周被赋予'9'和'5',其它的赋予'0' */
	x = W/2, y = H/2;		/*x,y是蛇的坐标，这里赋值使其在地图的中心 */
	head = &map[y][x + 1];	
	belly[l] = &map[y][x];		/* 蛇身 */
	tail = &map[y][x - 1];		/* 蛇尾 */
	*head = '1';			
		//蛇头指向的坐标赋予1
	*belly[0] = '2';			//蛇身赋予2
	*tail = '3';				//蛇尾赋予3
	L = '2', R = '8';
F = '6', B = '4';
}

void turn(char direction)
{
	switch (direction)
	{
	case '2':
		--y;		
		break;
	case '8':
		++y;
		break;
	case '4':
		--x;
		break;
	case '6':
		++x;
		break;
	}
}
void getfood()
{
	do
	{
		x1 = rand() % (W - 2) + 1;
		y2 = rand() % (H - 2) + 1;
			//随机函数产生食物坐标
	}
	while (map[y2][x1] != '0');
	food = &map[y2][x1];	
		//将食物指针指向得到的坐标
	*food = '4';			
		// 将坐标处的值替换成4
}
void draw()
{
	for (i = 0; i != H; i++)
	{
		for (j = 0; j != W; j++)
			switch (map[i][j])	
			// 对地图坐标代表的值进行判断
			{
			case '0'://0打印空白
				cout<<" ";
				break;
			case '9':	//左右墙体
				cout<<"\033[;31;m‖\033[m";
				break;
				case '5'://上下墙体
				cout<<"\033[;31;m=\033[m";
				break;
			case '1':			/* 遇到蛇头时 */
				cout<<"●";
				break;
			case '2':			/* 遇到蛇身时 */
				cout<<"▪";
				break;
			case '3':			/* 遇到蛇尾 */
				cout<<"▪";
				break;
			case '4':			/* 遇到食物 */
				cout<<"▪";
				break;
			}
	cout<<endl;		
	}
}

 void getturn()
{
	char t;					
	while (kbhit())	
	{
		t = getch();		
			/* 这个函数是得到一个输入 */
		if (t == L)			//判断输入的是不是L,L我们定义的是2
		{
			turn(L);
			L = B;		//方向转变
			B = R;
			R = F;
			F = t;
			goto gett;	
		}
		else if (t == R)	
		{
			turn(R);
			R = B;
			B = L;
			L = F;
			F = t;
			goto gett;
		}
	}
	turn(F);			
		//默认向前进
  gett:;
	while (kbhit())
		t = getch();
}
void move()
{
	tt = belly[l];				/* 零时的尾巴 */
	for (i = l; i != 0; --i)	
	/* 蛇身如果有多节，那么就伸长 */
		belly[i] = belly[i - 1];
	belly[0] = head;			/*因为蛇在前进，所以蛇身的第一节伸到原来的头部 */
	*belly[0] = '2';			
	/* 将值替换成蛇身的值 */
	head = &map[y][x];		
		/* 头部赋予新的坐标 */
}
int judge()
{
	switch (*head)			
		/* 判断头部的值是什么 */
	{
	case '2':
	case '9':
		cout<<"你的积分为:"<<J<<endl;	cout<<"游戏结束\n"<<endl;
		 l=0,J=0;//蛇长初始化，积分为0。
		Yes=1;
		break;
		/* 如果是蛇身或墙，直接游戏结束*/
	case '5':
		cout<<"你的积分为:"<<J<<endl;
	cout<<"游戏结束 \n"<<endl;
 l=0,J=0;//蛇长初始化，积分为0。
	Yes=1;
				break;
		/*如果是蛇身或墙，直接游戏结束*/
	case '4':			
			/* 如果是食物，那么我们吃掉它 */
		getfood();
		l++;
		J+=10;		
			/* 吃完之后蛇要伸长 ，积分增加*/
		belly[l] = tt;
		break;
	case '0':					
		*tail = '0';			/*把尾巴的值变成空白，因为我们移走了 */
	case '3':
		*head = '1';			/*如果是蛇尾，我们继续前进，不管 */
		tail = tt;
		*tail = '3';
		break;
	}
}
 void Snaker()
{
int difficult;
cout<<"\033[;32;m贪吃蛇游戏简单介绍:\n蛇体控制分别为数字键盘2（上），8（下），4（左），6（右），每吃到一次食物加10分，游戏结束后显示积分。\n\033[m";	cout<<"\033[;32;m请直接输入数字＂1.简单＂，＂2.中等＂，＂3.困难＂选择难度系数，游戏将在倒数5秒后开始，请注意转换为9宫格数字键盘。\033[m"<<endl;
cin>>difficult;
if (difficult==1)
N = 20;
else if (difficult==2)
N = 30;
else
N =40;	
for (i = 5;i >=0;i--)
{
	clrscr();
cout<<"\033[;31;m                     游戏开始倒数"<<"\033[m"<<"\033[;32;m"<<i<<"\033[m"<<"\033[;31;m秒\033[m";
usleep(1000000);
fflush(stdout);
clrscr();
}
clrscr();
	start();				
	turn(F);				//控制转向
	getfood();					//产生食物 
	draw();						// 画地图图 
	while (1)
	{
		usleep(4000000 / N);
		getturn();			
			//得到我们输入的转向
		move();				
		judge();				//判断函数
			if(Yes==1)
			break;
		clrscr();	
		draw();		
			/*不断清屏然后画地图 */
	}
}					
int main()                   
   /* 主程序，使用switch - case 选择功能。*/
{
  float L, N, M;
  int choice;
  cout << "\033[;31;m请输入你需要选择的计算器功能：" << endl;
  cout << "1.加法" << "                " << "2.减法" << endl;
  cout << "3.乘法" << "                " << "4.除法" << endl;
  cout << "5.开根号" << "              " << "6.解一元二次方程" <<
    endl;
  cout << "7.三四阶矩阵运算" << "      " << "8.等差等比数列求和"
    << endl;
  cout << "9.猜数字休闲小游戏" << "    "<<"0.贪吃蛇小游戏\033[m"<<endl;
  while (cin >> choice) {
    if (choice > 9)
      break;
    switch (choice) {
    case 1:
      cout << "\033[;36;m请输入需要计算的两个数:\n";
      while (cout << "加数:", cin >> N, cout << "被加数:", cin >> M) {
        cout << "和为:" << Sum(N, M) << endl;
        int jx;
        cout <<
          "如需再继续计算加法，请输入 1 ，否则请输入任意数字退出，按确认键即可\n";
        cin >> jx;
        if (jx == 1)
          continue;
        else
          break;
      }
      cout <<
        "如需再继续使用计算器的话请输入需要的计算器功能序号，或者请输入大于9的数字退出程序，按确认键即可。\n\n";
      break;
    case 2:
      cout << "\033[;36;m请输入需要计算的两个数:\n";
      while (cout << "减数:", cin >> N, cout << "被减数:", cin >> M) {
        cout << "差为:" << Sub(N, M) << endl;
        int jx;
        cout <<
          "如需再继续计算减法，请输入 1 ，否则请输入任意数字退出，按确认键即可。\n";
        cin >> jx;
        if (jx == 1)
          continue;
        else
          break;
      }
      cout <<
        "如需再继续使用计算器的话请输入需要的计算器功能序号，或者请输入大于9的数字退出程序，按确认键即可。\n\n\033[m";
      break;
    case 3:
      cout << "\033[;36;m请输入需要计算的两个数:\n";
      while (cout << "乘数:", cin >> N, cout << "被乘数:", cin >> M) {
        cout << "积为:" << Mul(N, M) << endl;
        int jx;
        cout <<
          "如需再继续计算乘法，请输入 1 ，否则请输入任意数字退出，按确认键即可。\n";
        cin >> jx;
        if (jx == 1)
          continue;
        else
          break;
      }
      cout <<
        "如需再继续使用计算器的话请输入需要的计算器功能序号，或者请输入大于9的数字退出程序，按确认键即可。\n\n\033[m";
      break;
    case 4:
      cout << "\033[;36;m请输入需要计算的两个数:\n";
      while (cout << "除数:", cin >> N, cout << "被除数:", cin >> M) {
        if (M == 0) {
          cout << "被除数不能为0，请重新输入。\n";
          cin >> M;
        }
        cout << "商为:" << Div(N, M) << endl;
        int jx;
        cout <<
          "如需再继续计算除法，请输入 1 ，否则请输入任意数字退出，按确认键即可。\n";
        cin >> jx;
        if (jx == 1)
          continue;
        else
          break;
      }
      cout <<
        "如需再继续使用计算器的话请输入需要的计算器功能序号，或者请输入大于9的数字退出程序，按确认键即可。\n\n\033[m";
      break;
    case 5:
      cout << "\033[;36;m请输入需要开根号的数:\n";
      while (cout << "需要开根号的数:", cin >> N) {
        cout << "结果为:" << Gh(N) << endl;
        int jx;
        cout <<
          "如需再继续计算开根号，请输入 1 ，否则请输入任意数字退出，按确认键即可。\n";
        cin >> jx;
        if (jx == 1)
          continue;
        else
          break;
      }
      cout <<
        "如需再继续使用计算器的话请输入需要的计算器功能序号，或者请输入大于9的数字退出程序，按确认键即可。\n\n\033[m";
      break;
    case 6:
      Set(L, N, M);
      cout <<
        "\033[;36;m如需再继续使用计算器的话请输入需要的计算器功能序号，或者请输入大于9的数字退出程序，按确认键即可。\n\n\033[m";
      break;
    case 7:
      Mot();
      cout <<
        "\033[;36;m如需再继续使用计算器的话请输入需要的计算器功能序号，或者请输入大于9的数字退出程序，按确认键即可。\n\n\033[m";
      break;
    case 8:
      EdLs();
      cout <<
        "\033[;36;m如需再继续使用计算器的话请输入需要的计算器功能序号，或者请输入大于9的数字退出程序，按确认键即可。\n\n\033[m";
      break;
    case 9:
      Csz_game();
      cout << "\033[;36;m如需再继续使用计算器的话请输入需要的计算器功能序号，或者请输入大于9的数字退出程序，按确认键即可。\n\n\033[m";
        break;
        case 0:
      Snaker();
      cout <<       "\033[;36;m如需再继续使用计算器的话请输入需要的计算器功能序号，或者请输入大于9的数字退出程序，按确认键即可。\n\n\033[m";
      Yes=0;
      break;
    default:
      cout << "选择错误，请重新选择。" << endl;
      break;
    }
    cout << "\033[;31;m下列是可以选择的计算器功能：" << endl;
    cout << "1.加法" << "                " << "2.减法" << endl;
    cout << "3.乘法" << "                " << "4.除法" << endl;
    cout << "5.开根号" << "              " << "6.解一元二次方程" <<
      endl;
    cout << "7.三四阶矩阵运算" << "      " <<
      "8.等差等比数列求和" << endl;
    cout << "9.猜数字休闲小游戏" << "    "<<"0.贪吃蛇小游戏\033[m"<<endl;
    cout << "***********************************************\n";
  }
  system("pause");
  return 0;
}