#define _CRT_SECURE_NO_WARNINGS 1

 /*
 ���㷨������ͼG��ĳ���㵽����ڵ�����·��pre�Լ�����dist
 ������ѭ����Ҫ�������£������ҳ�dist�����е���Сֵ������¼�±꣬˵���ҵ���ʼ�㵽���±�����·����
 Ȼ��Ҫ�ȼ۳�ʼ�㵽�õ�����·��������㵽������ʼ����Ҫ���ĵ�ľ����Ƿ�ȳ�ʼ��ֱ�ӵ���Щ��ľ����
 ���Ҫ�̣���ô�͸���dist���飬������Щ���ǰ���ڵ�ͻ��Ϊv�����ǿ�ʼ��v0�㡣��һ����ѭ����ȥ��dist����
 ��С��ֵ����δ����ĵ㣬���Ǹõ�����·����
 */
 #include<iostream>
#include<string>
#include<vector>
#include <algorithm>   
#include <fstream>     
#include <iomanip> 
 using namespace std;
 int matrix[100][100];//�ڽӾ���
 bool visited[100];//�������,�Ƿ��Ѿ�������·��
 int dist[100];//ԭ�㵽i�������̾���
 int pre[100];//��¼���·�����±ꡣpre[i]�ŵ���i��ǰ���ڵ�
 int source;//��һ���ڵ�
 int VStation_num;//������
 int I_num;//����
 
 void Dijkstra(int source)
 {
     //��ʼ��
     memset(visited,0,sizeof(visited));
     visited[source] = true;
     for (int i = 0; i < VStation_num; i++)
     {
         dist[i] = matrix[source][i];
         pre[i] = source;
     }
 
     int min_cost;//��̾���
     int min_cost_index;//Ȩֵ��С���Ǹ�������±ꡣ������ˣ�
     //��ѭ��
     for (int i = 1; i < VStation_num; i++)
     {
         min_cost = INT_MAX;
         for (int j = 0; j < VStation_num; j++)
         {
             //ע��Ҫȷ�������û���ҹ���
             if (visited[j]==false&&dist[j] < min_cost)
             {
                 min_cost_index = j;
                 min_cost = dist[j];
             }
         }
 
         visited[min_cost_index] = true;//�ҵ�ĳһ�������̾���
         //���øõ����dist�ĸ��£����ҵ���ǰ����
         for (int j = 0; j < VStation_num; j++)
         {
             //ȷ��������
             if (visited[j] == false && matrix[min_cost_index][j] != INT_MAX&&min_cost+ matrix[min_cost_index][j] < dist[j])
             {
                 dist[j] = min_cost + matrix[min_cost_index][j];
                 pre[j] = min_cost_index;
             }
         }
     }
 }
 
 void FileRead_P()
 {
	 vector<double> V;
	 vector<double>::iterator it;
	 ifstream data("������ˮ�����ݷ���.txt");
	 double d;
	 while (data >> d)
	 {
		 V.push_back(d);//�����ݴ�������V
	 }
	 data.close();
	 int i = 0;
	 it = V.begin();
	 for (int _pindex = 1; _pindex <= 2; _pindex++)
	 {
		 cout << "������ˮվP" << _pindex << "��һ����ˮվ�ľ��룺" << endl;
		 for (; it != V.end(); it++)
		 {
			 cout << "��V" << i << " �ľ��룺" << setprecision(16) << *it << endl;
			 i++;
			 if (i == 12)
			 {
				 i = 0;
				 it++;

				 cout << endl;
				 break;
			 }
		 }
	 }

 }
 int main()
 {
     cout << "������һ����ˮվ+����վ������Ŀ:";
     cin >> VStation_num;
     cout << "������I�͹ܵ������Ŀ: ";//ͼ�ı�
     cin >> I_num;
     for (int i = 0; i < VStation_num; i++)
     {
         for (int j = 0; j < VStation_num; j++)
         {
             matrix[i][j] = (i != j) ? INT_MAX : 0;
         }
     }
     cout << "������ÿ��������һ��վ���ŷ�Ͼ�����Ϣ��\n";
     int u, v, w;
     for (int i = 0; i < I_num; i++)
     {
         cin >> u >> v >> w;
         matrix[u][v] = matrix[v][u] = w;
     }
 
     cout << "������v1(<" << VStation_num << "): ";
     cin >> source;
     Dijkstra(source);
     for (int i = 0; i < VStation_num; i++)
     {
         if (i != source)
         {
             //·���Ƿ��ģ���Ŀ�����ǰ������ǰ���Ĺ��̡�
             cout << source << "��" << i << "��̾��룺 " << dist[i] << ",·���ǣ�" << i;
             int t = pre[i];
             while (t != source)
             {
                 cout << "--" << t;
                 t = pre[t];
             }
             cout << "--" << source << endl;
         }
     }

	 //����
	 FileRead_P();
	 Dijkstra(source);
	 system("pause");
     return 0;
 }