		#define _CRT_SECURE_NO_WARNINGS								//보안성 문제로 발생하는 scanf, fopen 오류무시
		#include <stdio.h> 
		#include <stdlib.h>
		#include <malloc.h>
		#include <string.h>

		typedef struct readlist{									//구조체선언
		char words[200];
		struct readlist* Next;
		}readlist;

		void Search(readlist* p);									//리스트 내 단어 검색 함수 

		int main()
		{
			FILE *fp = fopen("test.txt", "r");						//fopen : 파일열기, r : 텍스트모드로 읽기 
 			readlist* head = (readlist*)malloc(sizeof(readlist));	//head 리스트 선언 
			readlist* value = head;									//value 리스트 선언 
			head->Next = NULL;										//value가 가리키는 곳을 NULL로
		
		 	if (fp == NULL)											//text 오픈 실패시 error 메세지 출력
		 	{
		 		puts("file open error!!!!");
		 		return 0;
		 	}

		 	while (!feof(fp)){										//text에 있는 단어들을 linked list에 저장
		 		fscanf(fp, "%s ", value ->words);					//fscnaf : 파일에서 서식(%s)에 맞춰 읽는다.
		 		value->Next = (readlist*)malloc(sizeof(readlist));   
		 		value = value->Next;									//다음 리스트 주소를 현재 주소에 저장
				value->Next = NULL;									//다음 리스트를 가리킬 주소를 NULL
	}

			Search(head);											//검색 결과 출력 
	
			fclose(fp);												//파일 닫기 
			return 0;
	 }

		void Search(readlist* p) 									//리스트 내 단어 검색 함수 
		{
	 	char search_word[200];										//찾을 단어 저장할 배열
	 	int num = 0;
	 	int list_num = 1;
		int overlap = 0;											//중복된 단어의 수를 저장하기 위한 변수
	
		printf("찾을 단어 입력 : ");
	 	fflush(stdin);												//입력 버퍼를 비운다
		scanf("%s", search_word);									//찾을 단어 입력
	
		while (p->Next != NULL)										//리스트의 끝에 도착할 때까지 반복
		{
			if (_stricmp(search_word, p->words) == 0)				//stricmp : 대소문자를 구분하지 않고 비교하기
				{
					overlap++;										//몇개의 단어를 찾았는지 카운트
					printf("리스트 위치 : %d   ", list_num);		//리스트 위치 출력 
		 			num = 1;										
		 		}
				list_num++;											//리스트 번호 증가 
		 		p = p->Next;									        //다음으로 이동
		
			 	}
	 	if (!num)													//단어를 찾지 못할 경우 오류메세지
		 	{
		 		printf("error!!! 단어가 없습니다\n");
		 	}
		printf("중복된 단어 : %d\n", overlap);						//중복된 단어수 출력
		}
	