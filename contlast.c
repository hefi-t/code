#include "stdafx.h"
#define N 5 //�~�����Ɏg�p

int _tmain(int argc, _TCHAR* argv[])
{
	int a[5][5]={{3,3,2,3,3},
				 {3,2,1,2,3},
				 {3,1,0,1,3},
				 {3,2,1,2,3},
				 {3,3,2,3,3}};
	int i,j,k;

	int temp;
	double c;//�R���g���X�g
	double pmax;//�摜�̍ő��f
	double pmin;//�摜�̍ŏ���f

	double pave;//��f�l�̕���
	double dg;
	double psum;//��f���v
	double dgmax;
	double Cdg;

	int count[N];//�~����

	for(k=0;k<=N-1;k++)
		count[k]=0;

	printf("\t0\t1\t2\t3\t4\n");

	//�e��f���~�������߂�
	for(i=0;i<=4;i++)
	{
		printf("%d\t",i);
		for(j=0;j<=4;j++)
		{
			printf("%d\t",a[i][j]);
			count[a[i][j]]++;
		}
		printf("\n");
	}

	printf("\n");

	
	for(k=0;k<N;k++)
	{
		printf("�~����\t%d\t%d��\n",k,count[k]);
	}

	//�R���g���X�g�̌v�Z
	//pmin�����߂�
	for(k=0;k<N;k++)
	{
		if(count[k]!=0)
		{
			pmin=(double)k;
			break;
		}
	}
	//pmax�����߂�
	for(k=N-1;k>=0;k--)
	{
		if(count[k]!=0)
		{
			pmax=(double)k;
			break;
		}
	}

	printf("pmax=%lf,pmin=%lf\n",pmax,pmin);

	c=(pmax-pmin)/(pmax+pmin);//�R���g���X�g�̌v�Z
	
	printf("�R���g���X�g\tC=%lf\n",c);

	printf("\n�~���C����\n\n"); 
//��f���ςƍ�
	psum=0;
	pave=0;
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			psum+=(double)a[i][j];
		}
	}
	pave=psum/(double)(N*N);

	dgmax=pmax-pave;
	Cdg=0.5;//�␳�W��(0.1~0.5)
	dg=Cdg*dgmax;//�␳��

	printf("����(pave)%lf\n",pave);
	printf("�C��(dg)%lf\n",dg);

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i][j]>pave)
			{
				a[i][j]=a[i][j]+dg*(pmax-a[i][j])/(pmax-pave);
				if(a[i][j]>pmax)
				{
					a[i][j]=pmax;
				}
			}
			if(a[i][j]<pave)
			{
				a[i][j]=a[i][j]-dg*(pmax-a[i][j])/(pave-pmin);
				if(a[i][j]<0)
				{
					a[i][j]=0;
				}
			}
			
		}
		
	}
	

	//�\���̃v���O����
	for(k=0;k<=4;k++)
		count[k]=0;

	printf("\t0\t1\t2\t3\t4\n");

	for(i=0;i<=4;i++)
	{
		printf("%d\t",i);
		for(j=0;j<=4;j++)
		{
			printf("%d\t",a[i][j]);
			count[a[i][j]]++;
		}
		printf("\n");
	}

	printf("\n");

	for(k=0;k<N;k++)
	{
		printf("�~����\t%d\t%d\n",k,count[k]);
	}
		//�R���g���X�g�̌v�Z
	//pmin�����߂�
	for(k=0;k<N;k++)
	{
		if(count[k]!=0)
		{
			pmin=(double)k;
			break;
		}
	}
	//pmax�����߂�
	for(k=N-1;k>=0;k--)
	{
		if(count[k]!=0)
		{
			pmax=(double)k;
			break;
		}
	}

	printf("pmax=%lf,pmin=%lf\n",pmax,pmin);

	c=(pmax-pmin)/(pmax+pmin);//�R���g���X�g�̌v�Z
	
	printf("�R���g���X�g\tC=%lf\n",c);
	return 0;
}

