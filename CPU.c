#include <stdio.h>
#include <stdlib.h>
void fcfs_function();
void sjf_function();
void priority_function();
//void round_robin();
void get();
int main()
{
	int ch;
	while (1)
	{
		printf("\n1.FCFS");
		printf("\n2.SJF");
		printf("\n3.PB");
		//printf("\n4.RB");
		printf("\n4.Exit");
		printf("\nEnter your choice");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			fcfs_function();
			break;
		case 2:
			sjf_function();
			break;
		case 3:
			priority_function();
			break;
		/*case 4:
			//round_robin();
			 get();
			break;*/
		 case 4:
			exit(0);
		default:
			printf("Wrong choice please enter correct choice");
		}
	}
}
void fcfs_function()
{
	int burst[5], wait[5], turn[5], n, x = 0, i;
	float total_wait = 0, total_turn = 0, avg_wait, avg_turn;
	double t_put;
	printf("\nMaximum 5 process you can enter \nHow many process do you want to enter?");
	scanf("%d", &n);
	printf("\nEnter the processes and its CPU Burst time");
	for (i = 0; i < n; i++)
	{
		printf("\nEnter the CPU Burst of P%d ", i + 1);
		scanf(" %d", &burst[i]);
	}
	printf("\n\nWaiting Time calculation");
	wait[0] = 0;
	for (i = 1; i < n; i++)
	{
		wait[i] = burst[i - 1] + wait[i - 1];
	}
	for (i = 0; i < n; i++)
	{
		printf("\nWaiting time of P%d = %d", i + 1, wait[i]);
	}
	printf("\n\nTurnaround Time calculation");
	for (i = 0; i < n; i++)
	{
		turn[i] = burst[i] + wait[i];
		printf("\nTurnaround time of P%d = %d", i + 1, turn[i]);
	}
	printf("\n\nAverage waiting time = ");
	for (i = 0; i < n; i++)
	{
		total_wait = wait[i] + total_wait;
	}
	avg_wait = total_wait / n;
	printf("%f", avg_wait);
	printf("\n\nAverage Turnaround time = ");
	for (i = 0; i < n; i++)
	{
		total_turn = turn[i] + total_turn;
	}
	avg_turn = total_turn / n;
	printf("%f", avg_turn);
	/*printf("\nThroughput = ");
	t_put=n/wait[n-1];
	printf("%lf",t_put);*/
}
void sjf_function()
{
	int burst[5], wait[5], turn[5], n, x = 0, i, p[5], a, b, pos, temp;
	float total_wait = 0, total_turn = 0, avg_wait, avg_turn;
	double t_put;
	printf("\nMaximum 5 process you can enter \nHow many process do you want to enter?");
	scanf("%d", &n);
	printf("\nEnter the processes and its CPU Burst time");
	for (i = 0; i < n; i++)
	{
		printf("\nEnter the CPU Burst of P%d ", i + 1);
		scanf(" %d", &burst[i]);
		p[i] = i + 1;
	}

	for (a = 0; a < n; a++)
	{
		pos = a;
		for (b = a + 1; b < n; b++)
		{
			if (burst[b] < burst[pos])
				pos = b;
		}
		// sorting process according to shortest cpu burst
		temp = burst[a];
		burst[a] = burst[pos];
		burst[pos] = temp;

		temp = p[a];
		p[a] = p[pos];
		p[pos] = temp;
	}

	printf("\n\nWaithing time calculation");
	wait[0] = 0;
	for (i = 1; i < n; i++)
	{
		wait[i] = burst[i - 1] + wait[i - 1];
	}
	for (i = 0; i < n; i++)
	{
		printf("\nWaiting time of P%d = %d", p[i], wait[i]);
	}

	printf("\n\nTurnaround Time calculation");
	for (i = 0; i < n; i++)
	{
		turn[i] = burst[i] + wait[i];
		printf("\nTurnaround time of P%d = %d", p[i], turn[i]);
	}
	printf("\n\nAverage waiting time = ");
	for (i = 0; i < n; i++)
	{
		total_wait = wait[i] + total_wait;
	}
	avg_wait = total_wait / n;
	printf("%f", avg_wait);
	printf("\n\nAverage Turnaround time = ");
	for (i = 0; i < n; i++)
	{
		total_turn = turn[i] + total_turn;
	}
	avg_turn = total_turn / n;
	printf("%f", avg_turn);
}

void priority_function()
{
	int burst[5], wait[5], turn[5], n, x = 0, i, p[5], a, b, pos, temp, pri[5];
	float total_wait = 0, total_turn = 0, avg_wait, avg_turn;
	double t_put;
	printf("\nMaximum 5 process you can enter \nHow many process do you want to enter?");
	scanf("%d", &n);
	printf("\nEnter the processes and its CPU Burst time");
	for (i = 0; i < n; i++)
	{
		printf("\nEnter the CPU Burst of P%d ", i + 1);
		scanf(" %d", &burst[i]);
		p[i] = i + 1;
	}
	printf("\nEnter the priority of the processes");
	for (i = 0; i < n; i++)
	{
		printf("\nEnter the  priority of P%d ", i + 1);
		scanf(" %d", &pri[i]);
	}
	for (a = 0; a < n; a++)
	{
		pos = a;
		for (b = a + 1; b < n; b++)
		{
			if (pri[b] < pri[pos])
				pos = b;
		}
		// sorting the processes according to priority
		temp = burst[a];
		burst[a] = burst[pos];
		burst[pos] = temp;

		temp = p[a];
		p[a] = p[pos];
		p[pos] = temp;
	}
	printf("\n\nWaithing time calculation");
	wait[0] = 0;
	for (i = 1; i < n; i++)
	{
		wait[i] = burst[i - 1] + wait[i - 1];
	}
	for (i = 0; i < n; i++)
	{
		printf("\nWaiting time of P%d = %d", p[i], wait[i]);
	}

	printf("\n\nTurnaround Time calculation");
	for (i = 0; i < n; i++)
	{
		turn[i] = burst[i] + wait[i];
		printf("\nTurnaround time of P%d = %d", p[i], turn[i]);
	}
	printf("\n\nAverage waiting time = ");
	for (i = 0; i < n; i++)
	{
		total_wait = wait[i] + total_wait;
	}
	avg_wait = total_wait / n;
	printf("%f", avg_wait);
	printf("\n\nAverage Turnaround time = ");
	for (i = 0; i < n; i++)
	{
		total_turn = turn[i] + total_turn;
	}
	avg_turn = total_turn / n;
	printf("%f", avg_turn);
}

/*void round_robin()
{
	int burst[5], wait[5], turn[5], n, x = 0, i, t, rt[5], temp[i];
	float total_wait = 0, total_turn = 0, avg_wait, avg_turn;
	double t_put;
	printf("\nMaximum 5 process you can enter \nHow many process do you want to enter?");
	scanf("%d", &n);
	printf("\nEnter the processes and its CPU Burst time");
	for (i = 0; i < n; i++)
	{
		printf("\nEnter the CPU Burst of P%d ", i + 1);
		scanf(" %d", &burst[i]);
	}
	printf("\nEnter the time slice for the processes ");
	scanf("%d", &t);
	for (i = 0; i < n; i++)
	{
		temp[i] = burst[i];
	}
	for (i = 0; i < n; i++)
	{
		if (temp[i] <= t && temp[i] > 0)
		{
			burst[i] = temp[i];
		}
		else if (temp[i] > t)
		{
			temp[i] = t - temp[i];
			burst[i] = temp[i];
		}
		else if (temp[i] - t == 0 || temp[i] - t < t)
		{
			burst[i] = temp[i];
		}
	}

		printf("\n\nWaiting Time calculation");
		wait[0] = 0;
		for (i = 1; i < n; i++)
		{
			wait[i] = burst[i - 1] + wait[i - 1];
		}
		for (i = 0; i < n; i++)
		{
			printf("\nWaiting time of P%d = %d", i + 1, wait[i]);
		}
		printf("\n\nTurnaround Time calculation");
		for (i = 0; i < n; i++)
		{
			turn[i] = burst[i] + wait[i];
			printf("\nTurnaround time of P%d = %d", i + 1, turn[i]);
		}
		printf("\n\nAverage waiting time = ");
		for (i = 0; i < n; i++)
		{
			total_wait = wait[i] + total_wait;
		}
		avg_wait = total_wait / n;
		printf("%f", avg_wait);
		printf("\n\nAverage Turnaround time = ");
		for (i = 0; i < n; i++)
		{
			total_turn = turn[i] + total_turn;
		}
		avg_turn = total_turn / n;
		printf("%f", avg_turn);
	
}*/
