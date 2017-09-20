#include<reg52.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define PCF8591_ADDR	0x90		//PCF8591地址
uchar code table[]="   2000-00-00 "; // 1602初始数据
uchar code table1[]=" 00:00:00";
uchar num,AD_Value,count,count1,shi,fen,miao,s1num,ri,yue,nian;
sbit dula = P2^6;
sbit wela = P2^7;
sbit SDA = P2^0;  // I2C数据线
sbit SCL = P2^1;  // I2C时钟线
sbit E181 = P2^2;// 测距传感器1(是否有人)（蓝）
sbit E182 = P2^4;// 测距传感器2(是否过近)（红）
sbit kaiguan = P2^5; // 模式切换开关
sbit lcden = P3^4;// 使能端位定义
sbit lcdrs = P3^5;// 命令/数据选择端位定义
sbit lcdwr = P3^6;// 读/写选择端位定义
sbit fm = P2^3;	 // 蜂鸣器
/*要用3个独立按键s1，s2，s3来调整数字"秒、分、时、日、月、年，s1按键作为跳到要调整的位上，
  s2按键作为数据的递增，s3按键作为数据的递减"*/
sbit s1 = P3^0;
sbit s2 = P3^1;
sbit s3 = P3^2;

void delay(uint z) // zms延时函数
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=114;y>0;y--);
}

/*5us延时*/
void delay_5us()  
{
	_nop_();
}

void write_com(uchar com) // 写命令子函数（结合写操作时序图）
{
	lcdrs = 0;// 命令/数据选择端(置0选择写“命令”)
	P0 = com; // 送数据
	delay(5); // 延时										   
	lcden = 1;// 使能端给高脉冲
	delay(5); // 延时										  
	lcden = 0;// 使能端给低脉冲	
}

void write_data(uchar date)// 写数据子函数（结合写操作时序图）
{
	lcdrs = 1; // 命令/数据选择端(置1选择写“数据”)
	P0 = date;
	delay(5);												 
	lcden = 1;
	delay(5);												
	lcden = 0;	
}

void init()
{
	wela = 1; // 位锁存端（以使数码管保持不亮）
	P0 = 0xff;
	wela = 0;
	dula = 1; // 段锁存端（以使数码管保持不亮）
	P0 = 0x00;
	dula = 0; 
	lcden = 0;// 使能端初始化
	lcdwr = 0;// 读/写选择端初始化（置0，选择写数据）
	write_com(0x38);//	设置16*2显示，5*7点阵，8位数据接口
	write_com(0x0c);// 开显示，关光标
	write_com(0x06);// 光标加1，且不移动
	write_com(0x80);// 设置数据地址（第一个字）
	for(num = 0;num < 14;num++)							  
	{
		write_data(table[num]);
		delay(10); // 每隔约10ms显示一个字符			   
	}
	write_com(0x80+0x43);//0x80表示从第一行第一个字开始显示,再加0x43从第二行第4个字开始显示
	for(num = 0;num < 9;num++)
	{
		write_data(table1[num]);
		delay(10); // 每隔约10ms显示一个字符			  
	}
	TMOD = 0x11;// 定时器0-工作方式1，定时器1-工作方式1
	TH0 = (65536-50000)/256;
	TL0 = (65536-50000)%256;
	ET0 = 1;	
	TR0 = 1;
	TH1 = (65536-50000)/256;
	TL1 = (65536-50000)%256;
	ET1 = 1;
	TR1 = 0;  // 初始时，先关闭定时器1
	EA = 1;	
}	

void shifenmiao(uchar add,uchar date)/*这个子函数用于刷新时、分、秒变化后数值，
 列如00:00:00,在秒每次加1之后，都要送入新的数值给”所对应地址上的“秒“，并且秒是两位数据，
 所以要将这两位数据分离开来分别送到对应的位置，而且送的数据应该是这个数据对应的16进制编码，
 0所对应的十六进制编码为0x30（根据字符手册），故对于某一数值x，它对应的16进制编码应该是0x30+x*/
{
	uchar shi,ge;
	shi = date/10;
	ge = date%10;
	write_com(0x80+0x40+add);//确定出所要送的时(分或秒)的数据的地址（以便下面送入数据）
	write_data(0x30+shi); //将时(分或秒)的数据的十位送到上面行中的地址
	write_data(0x30+ge);  //将时(分或秒)的数据的个位送到上面行中的地址
}

void riyuenian(uchar add1,uchar date1)/*这个子函数用于刷新日、月、年变化后数值，具体过程同时、分、秒*/
{
	uchar shi1,ge1;
	shi1 = date1/10;
	ge1 = date1%10;
	write_com(0x80+add1);//确定出所要送的日(月或年)的数据的地址（以便下面送入数据）
	write_data(0x30+shi1); //将日(月或年)的数据的十位送到上面一行中的地址
	write_data(0x30+ge1);  //将日(月或年)的数据的个位送到上面的地址
}

void keyscan()
{
	if(s1==0)// 如果第一个键按下	
	{
		delay(5);//消抖
		if(s1==0) // 如果第一个键确实按下
		{	
			s1num++;// s1num记录闪烁的顺序
			while(!s1);// 第一个键的松手检测
			if(s1num==1) // 如果光标在”秒“上闪烁
			{
				TR0=0;// 闪烁时关闭定时器
				write_com(0x80+0x40+11);// 确定"秒"的地址
				write_com(0x0f);//开显示，开光标闪烁，等待修改
			}
		 }
		if(s1num==2)// 如果光标在”分“上闪烁
		{
			write_com(0x80+0x40+8);// 确定"分"的地址
		}
		if(s1num==3) // 如果光标在”时“上闪烁
		{
			write_com(0x80+0x40+5);// 确定"时"的地址
		}
		if(s1num==4) // 如果光标在”日“上闪烁
		{
			write_com(0x80+12);// 确定"日"的地址
		}
		if(s1num==5) // 如果光标在”月“上闪烁
		{
			write_com(0x80+9);// 确定"月"的地址
		}
		if(s1num==6) // 如果光标在”年“上闪烁
		{
			write_com(0x80+6);// 确定"年"的地址
		}
		if(s1num==7) // 停止闪烁
		{
			s1num=0;
			write_com(0x0c);//开显示，关光标闪烁
			TR0=1;// 开定时器，继续计时
		}			
	}
	if(s1num!=0)// 在第一个键按下之后如果再有键按下（即光标在闪烁）
	{
		if(s2==0) // 按下第二个键
		{
			delay(5);//消抖
			if(s2==0) // 确实按下第二个键
			{
				while(!s2);// 第二个键的松手检测
				if(s1num==1)//如果光标在”秒“上闪烁,那么本层if循环对”秒“的数据进行修改
				{
					miao++;
					if(miao==60)// 秒的增加到达60，则要清零
						miao=0;
					shifenmiao(10,miao);//发送数据	
					write_com(0x80+0x40+11);// 确定修改数据的地址		
				}
				if(s1num==2)//如果光标在”分“上闪烁,那么本层if循环对”分“的数据进行修改
				{
					fen++;
					if(fen==60)// 同上
						fen=0;
					shifenmiao(7,fen);// 同上
					write_com(0x80+0x40+8);	// 同上		
				}
				if(s1num==3)//如果光标在”时“上闪烁,那么本层if循环对”时“的数据进行修改
				{
					shi++;
					if(shi==24)// 同上
						shi=0;
					shifenmiao(4,shi);// 同上
					write_com(0x80+0x40+5);// 同上	
				}
				if(s1num==4)//如果光标在”日“上闪烁,那么本层if循环对”日“的数据进行修改
				{
					ri++;
					if(ri==31)// 同上
						ri=1;
					riyuenian(11,ri);
					write_com(0x80+12);//同上	
				}
				if(s1num==5)//如果光标在”月“上闪烁,那么本层if循环对”月“的数据进行修改
				{
					yue++;
					if(yue == 13)
						yue = 1;
					riyuenian(8,yue);
					write_com(0x80+9);//同上	
				}
				if(s1num==6)//如果光标在”年“上闪烁,那么本层if循环对”年“的数据进行修改
				{
					nian++;
					if(nian == 100)
						nian = 0;
					riyuenian(5,nian);
					write_com(0x80+6);//同上	
				}
			}
		}
		if(s3==0)// 如果按下第三个键
	    {
			delay(5);//消抖
			if(s3==0)
			{
				while(!s3);// 第三个键的松手检测
				if(s1num==1)//如果光标在”秒“上闪烁,那么本层if循环对”秒“的数据进行修改
				{
					miao--;
					if(miao==-1)// 如果秒为负数，则退回59
						miao=59;
					shifenmiao(10,miao);
					write_com(0x80+0x40+11);	
				}
				if(s1num==2)//如果光标在”分“上闪烁,那么本层if循环对”分“的数据进行修改
				{
					fen--;
					if(fen==-1)	 //同上
						fen=59;	
					shifenmiao(7,fen);//同上
					write_com(0x80+0x40+8);//同上	
				}
				if(s1num==3)//如果光标在”时“上闪烁,那么本层if循环对”时“的数据进行修改
				{
					shi--; //同上
					if(shi==-1)	//同上
						shi=23;
					shifenmiao(4,shi);
					write_com(0x80+0x40+5);	//同上	
				}
			    if(s1num==4)//如果光标在”日“上闪烁,那么本层if循环对”日“的数据进行修改
				{
					ri--; //同上
					if(ri==-1)	//同上
						ri=30;
					riyuenian(11,ri);
					write_com(0x80+12);	//同上	
				}
				if(s1num==5)//如果光标在”月“上闪烁,那么本层if循环对”月“的数据进行修改
				{
					yue--;
					if(yue == -1)
						yue = 12;
					riyuenian(8,yue);
					write_com(0x80+9);//同上	
				}
				if(s1num==6)//如果光标在”年“上闪烁,那么本层if循环对”年“的数据进行修改
				{
					nian--;
					if(nian == -1)
						nian = 99;
					riyuenian(5,nian);
					write_com(0x80+6);//同上	
				}
			}
	    }	
	}		
}

/*I2C初始化*/
void I2C_init()	
{
	SDA = 1;
	_nop_(); // 短暂延时（约1ms），从而使总线稳定 ，以下_nop_()的作用与此相同
	SCL = 1;
	_nop_();
}

/*I2C起始信号*/
void I2C_Start()  
{
	SCL = 1;
	_nop_();
	SDA = 1;
	delay_5us();
	SDA = 0;
	delay_5us();
}

/*I2C终止信号*/
void I2C_Stop()
{
	SDA = 0;
	_nop_();
	SCL = 1;
	delay_5us();
	SDA = 1;
	delay_5us();
}

/*主机向从机发送应答（由从机检测）*/
void Master_ACK(bit i)		
{
	SCL = 0; // 拉低时钟总线允许SDA数据总线上的数据变化
	_nop_(); // 让总线稳定
	if (i)	 //如果i = 1 那么拉低数据总线 表示主机应答
	{
		SDA = 0;     //表示主机应答
	}
	else	 
	{
		SDA = 1;	//表示主机非应答
	}
	_nop_();//让总线稳定
	SCL = 1;//拉高时钟总线 让从机从SDA线上读走 主机的应答信号
	delay_5us();
	SCL = 0;//拉低时钟总线， 占用总线继续通信
	_nop_();
	SDA = 1;//释放SDA数据总线。
	_nop_();
}

/*从机向主机发送应答（由主机检测）*/
bit Test_ACK()
{
	SCL = 1; // 时钟线为高时，可读取应答信号
	delay_5us();
	if (SDA)   // 如果从机没有应答
	{
		SCL = 0;// 因为从机没有应答，故主机要发停止信号，所以先将SCL拉低以允许数据变化
		_nop_();
		I2C_Stop();	// 主机发停止信号，结束本次通信
		return(0);  // 返回一个“0”,表示从机非应答
	}
	else	// 从机应答
	{
		SCL = 0;  // SCL依然要拉低，这是为主机向从机发数据做准备
		_nop_();
		return(1); // 返回一个“0”,表示从机应答
	}
}

/*I2C发送一个字节*/
void I2C_send_byte(uchar byte)
{
	uchar i;
	for(i = 0 ; i < 8 ; i++)
	{
		SCL = 0;  // 允许数据变化
		_nop_();
		if (byte & 0x80) // 如果为真，表明byte最高位为1，那么将这个“1”发送给SDA，然后发出去
		{				
			SDA = 1;	
			_nop_();				   
		}				
		else   // 如果为假，表明byte最高位为0，那么将这个“0”发送给SDA，然后发出去
		{
			SDA = 0;
			_nop_();
		}
		SCL = 1;  // 将SCL拉高，读取SDA总线数据
		_nop_();
		byte <<= 1;	//byte左移1位，为下次数据发送做准备 
	}
	SCL = 0;
	_nop_();
	SDA = 1;
	_nop_();
}
 
/*I2C 读一个字节*/
uchar I2C_read_byte()
{
	uchar dat,i; // 读取到的数据存入dat
	SCL = 0;
	_nop_();
	SDA = 1;  // 释放总线
	_nop_();
	for(i = 0 ; i < 8 ; i++)
	{
		SCL = 1; // SCL为高，准备读取数据
		_nop_();
		if (SDA) // 如果读到一个“1”			    
		{
			 dat |= 0x01; // 将读到的“1”存入dat的最低位
		}
		else  // 如果读到一个“0”
		{
			dat &=  0xfe;	// 将读到的“0”存入dat的最低位
		}
		_nop_();
		SCL = 0 ;
		_nop_();
		if(i < 7) /*因为一共要读取8次，每次都存放在最低位，故每次存放之后都要左移一位，为下次读取做准备，
		         【注意】：读取8次，只要左移7次，因为最后一次正好存放在最低位,不需要再移位*/
		{
			dat = dat << 1;	
		}
	}
	return(dat);//将读取到的一个字节返回给dat
}

/*I2C接收（读取）数据的过程*/
/*读AD数据*/
bit ADC_Read(uchar CON)	// 本函数同AT24C02芯片接收数据时的receive函数作用相同，都是将数据存入芯片
{
	I2C_Start();
	I2C_send_byte(PCF8591_ADDR+0); // PCF8591地址 0x90
	if (!Test_ACK())
	{
		return(0);
	}
	I2C_send_byte(CON);		//写入PCF8591控制字 
	Master_ACK(0);
	I2C_Start();
	I2C_send_byte(PCF8591_ADDR+1);
	if (!Test_ACK())
	{
		return(0);
	}
	AD_Value = I2C_read_byte();
	Master_ACK(0);
	I2C_Stop();
	return(1);	
}

void test_time() // 测试入座时间
{				
	if(E181 == 0)
	{
		TR1 = 1;
		if(count1 == 100) // 计时5秒到，亮警示灯   
		{
			count1 = 0;
			fm = 0;
			delay(1000);// 警示灯延时
			fm = 1;
			delay(1000);// 警示灯延时	
		}
	}
	else
	TR1 = 0;		
} 

void test_distance() // 测试距离
{
	if(E182 == 0)
	{
		fm = 0;
		delay(500);// 警示灯延时
		fm = 1;
	    delay(500);// 警示灯延时
	}	
}

void test_light() // 光控亮灯
{
	ADC_Read(0x02); // 将返回值date发送给num   【注】：0x02为PCF8591的控制字	 
	if((AD_Value > 150)&&(E181 == 0))	      // 光照强度值num大于180时，灯自动点亮
	P1 = 0;
	else 
	P1 = 0xff;	
}

void main()
{
	init();
	I2C_init();
	while(1)
	{	
		keyscan();
	    if(kaiguan == 0) // 智能模式（1602显示+光控亮灯+定时提醒+测距）
		{		
			test_light();
			test_distance();
			test_time();
		}
		else // 普通模式 （1602显示+常亮灯）
		{
			P1 = 0x00;
		}				
	}		
}
		
void timer0() interrupt 1//定时器0，工作方式1
{
	TH0 = (65536-50000)/256;
	TL0 = (65536-50000)%256;
	count++;
	if(count == 18)//计时1秒到
		{
			count = 0;
			miao++;
			if(miao == 60)//计时1分钟到
			{
				miao = 0;
				fen++;
				if(fen == 60)//计时1小时到
				{
					fen = 0;
					shi++;
					if(shi == 24)//计时1日到
					{
						shi = 0;
						ri++;
						if(ri == 31) //计时1个月到
						{
							ri = 1;
							yue++;
							if(yue == 13)//计时1年到
							{
								yue = 1;
								nian++;
								if(nian == 100)//计时99年到
								{
									nian = 0;
								}
								riyuenian(5,nian);//调用子函数用于刷新“年”的数据，并且显示在其指定的地址：0x80+5
							}
							riyuenian(8,yue);//刷新”月“，显示在：0x80+8
						}
						riyuenian(11,ri);//刷新”日“，显示在：0x80+11
					}
					shifenmiao(4,shi);//刷新“时”，显示在：0x80+0x40+4
				}
				shifenmiao(7,fen);//刷新”分“，显示在：0x80+0x40+7
			}
		  shifenmiao(10,miao);//刷新”秒“，显示在：0x80+0x40+10
		}		
}

void timer1() interrupt 3//定时器1，工作方式1
{
	TH1 = (65536-50000)/256;
	TL1 = (65536-50000)%256;
	count1++;			
}























