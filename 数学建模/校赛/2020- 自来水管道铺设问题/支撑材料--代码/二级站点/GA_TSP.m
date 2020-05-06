clear
clc
close all

%��������

%load ('E:\1958214014\FileRecv\city_location.mat');

%���ӻ�����
location = load ('city_location.mat');
x = location.unnamed(:,1);
y = location.unnamed(:,2);
plot(x,y,'ko');
xlabel('����վ�������x');
ylabel('����վ��������y');
grid on;

NIND = 100;         %��Ⱥ��С
MAXGEN = 3000;       %����������
Pc = 0.9;           %������ʣ��൱�ڻ����Ŵ���ʱ��Ⱦɫ�彻��
Pm = 0.05;          %Ⱦɫ�����
GGAP = 0.9;         %����Ǵ�����ͨ���Ŵ���ʽ�õ����Ӵ���Ϊ������*GGAP
D = Distance(city_location);    %ͨ������������Լ���i,j����֮��ľ���
N = size(D,1);      %�����ж��ٸ������
%%��ʼ����Ⱥ
Chrom = InitPop(NIND,N);    %Chrome�������Ⱥ
%%����������·��ͼ
DrawPath(Chrom(1,:),city_location)
pause(0.0001)
%���������·�ߺ��ܾ���
disp('��ʼ��Ⱥ�е�һ�����ֵ')
OutputPath(Chrom(1,:));%����һ������
Rlength = PathLength(D,Chrom(1,:));
disp(['�ܾ���;',num2str(Rlength)]);
disp('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')
%�Ż�
gen = 0;
figure;
hold on;
box on;
xlim([0,MAXGEN])
title('�Ż�����')
xlabel('��������')
ylabel('��ǰ���Ž�')
ObjV = PathLength(D,Chrom);%���㵱ǰ·�߳��ȣ������������������Щ����·��
preObjV = min(ObjV);%��ǰ���Ž�
while gen<MAXGEN
    %%������Ӧ��
    ObjV = PathLength(D,Chrom);     %����·�߳���
    line([gen - 1,gen],[preObjV,min(ObjV)]);
    pause(0.0001);
    preObjV = min(ObjV);
    FitnV = Fitness(ObjV);
    %ѡ��
    SelCh = Select(Chrom,FitnV,GGAP);
    %�������
    SelCH = Recombin(SelCh,Pc);
    %����
    SelCh = Mutate(SelCh,Pm);
    %��ת����
    SelCh = Reverse(SelCh,D);
    %�ز����Ӵ�������Ⱥ
    Chrom = Reins(Chrom,SelCh,ObjV);
    %���µ�������
    gen = gen + 1;
end
%�������Ž��·��ͼ
ObjV = PathLength(D,Chrom);     %����·�߳���
[minObjV,minInd] = min(ObjV);
DrawPath(Chrom(minInd(1),:),city_location)
%%������Ž��·�ߺ;���
disp('���Ž�:')
p = OutputPath(Chrom(minInd(1),:));
disp(['�������߹����ܾ��룺',num2str(ObjV(minInd(1)))]);
disp('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')