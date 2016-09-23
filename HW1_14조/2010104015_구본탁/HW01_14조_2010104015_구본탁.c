		#define _CRT_SECURE_NO_WARNINGS								//���ȼ� ������ �߻��ϴ� scanf, fopen ��������
		#include <stdio.h> 
		#include <stdlib.h>
		#include <malloc.h>
		#include <string.h>

		typedef struct readlist{									//����ü����
		char words[200];
		struct readlist* Next;
		}readlist;

		void Search(readlist* p);									//����Ʈ �� �ܾ� �˻� �Լ� 

		int main()
		{
			FILE *fp = fopen("test.txt", "r");						//fopen : ���Ͽ���, r : �ؽ�Ʈ���� �б� 
 			readlist* head = (readlist*)malloc(sizeof(readlist));	//head ����Ʈ ���� 
			readlist* value = head;									//value ����Ʈ ���� 
			head->Next = NULL;										//value�� ����Ű�� ���� NULL��
		
		 	if (fp == NULL)											//text ���� ���н� error �޼��� ���
		 	{
		 		puts("file open error!!!!");
		 		return 0;
		 	}

		 	while (!feof(fp)){										//text�� �ִ� �ܾ���� linked list�� ����
		 		fscanf(fp, "%s ", value ->words);					//fscnaf : ���Ͽ��� ����(%s)�� ���� �д´�.
		 		value->Next = (readlist*)malloc(sizeof(readlist));   
		 		value = value->Next;									//���� ����Ʈ �ּҸ� ���� �ּҿ� ����
				value->Next = NULL;									//���� ����Ʈ�� ����ų �ּҸ� NULL
	}

			Search(head);											//�˻� ��� ��� 
	
			fclose(fp);												//���� �ݱ� 
			return 0;
	 }

		void Search(readlist* p) 									//����Ʈ �� �ܾ� �˻� �Լ� 
		{
	 	char search_word[200];										//ã�� �ܾ� ������ �迭
	 	int num = 0;
	 	int list_num = 1;
		int overlap = 0;											//�ߺ��� �ܾ��� ���� �����ϱ� ���� ����
	
		printf("ã�� �ܾ� �Է� : ");
	 	fflush(stdin);												//�Է� ���۸� ����
		scanf("%s", search_word);									//ã�� �ܾ� �Է�
	
		while (p->Next != NULL)										//����Ʈ�� ���� ������ ������ �ݺ�
		{
			if (_stricmp(search_word, p->words) == 0)				//stricmp : ��ҹ��ڸ� �������� �ʰ� ���ϱ�
				{
					overlap++;										//��� �ܾ ã�Ҵ��� ī��Ʈ
					printf("����Ʈ ��ġ : %d   ", list_num);		//����Ʈ ��ġ ��� 
		 			num = 1;										
		 		}
				list_num++;											//����Ʈ ��ȣ ���� 
		 		p = p->Next;									        //�������� �̵�
		
			 	}
	 	if (!num)													//�ܾ ã�� ���� ��� �����޼���
		 	{
		 		printf("error!!! �ܾ �����ϴ�\n");
		 	}
		printf("�ߺ��� �ܾ� : %d\n", overlap);						//�ߺ��� �ܾ�� ���
		}
	