#include "header.h"

int prev = -1;
int prevv = -1;

/*make date using unicode and fill the queue*/
void decoder(Queue_char *queue, int unicode);

/*check prev unicode is figure*/
int prev_is_figure();

/*check prev unicode is Latin*/
int prev_is_Latin();

/*print to console*/
void print_queue(Queue_char *queue);

/*print to console like module*/
void print_module(unsigned char *data);

int prev_is_figure() {
	if (prev >= 0x0030 && prev <= 0x0039)
		return 1;
	else
		return 0;
}

int prev_is_Latin() {
	if ((prev >= 0x0041 && prev <= 0x005A) || (prev >= 0x0061 && prev <= 0x007A))
		return 1;
	else
		return 0;
}

void print_queue(Queue_char *queue) {
	unsigned char data[MODULE_CNT];
	int bit = 2;
	Queue_char* copy = queue_copy_char(queue);
	printf("========================================\n");
	while (!IsEmpty_char(copy)) {
		memset(data, 0x00, sizeof(unsigned char) * MODULE_CNT);
		for (int i = 0;i < MODULE_CNT;i++) {
			if (IsEmpty_char(copy))
				break;
			data[i] = Dequeue_char(copy);
		}
		for (int i = 0;i < 3;i++) {
			for (int j = 0;j < MODULE_CNT;j++) {
				for (int k = 0;k < 2;k++) {
					if (data[j] & (bit << ((i * 2) + k)))
						printf("● ");
					else
						printf("○ ");
				}
				printf("  ");
			}
			printf("\n");
		}
	}
	printf("========================================\n");
}

void print_module(unsigned char *data) {
	int bit = 2;
	printf("========================================\n");
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < MODULE_CNT;j++) {
			for (int k = 0;k < 2;k++) {
				if (data[j] & (bit << ((i * 2) + k)))
					printf("● ");
				else
					printf("○ ");
			}
			printf("  ");
		}
		printf("\n");
	}
	printf("========================================\n");
}

void decoder(Queue_char *queue, int unicode) {
	unsigned char data;
	switch (unicode) {
		/**********************초성************************/
		case 0x1100: // ㄱ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1];
			Enqueue_char(queue, data);
			break;
		case 0x1102: // ㄴ
			if (prev_is_figure())
				Enqueue_char(queue, 0);
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[1];
			Enqueue_char(queue, data);
			break;
		case 0x1103: // ㄷ	
			if (prev_is_figure())
				Enqueue_char(queue, 0);
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1] + SOL_NUM[2];
			Enqueue_char(queue, data);
			break;
		case 0x1105: //ㄹ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x1106: //ㅁ
			if (prev_is_figure())
				Enqueue_char(queue, 0);
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x1107: // ㅂ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x1109: //ㅅ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x110B: // ㅇ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			if ((prev == 0x1161) && (prevv == 0x1102 || prevv == 0x1103 || prevv == 0x1106 || prevv == 0x1107 || prevv == 0x110C || prevv == 0x110F || prevv == 0x1110 || prevv == 0x1111 || prevv == 0x1112)) {
				data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			break;
		case 0x110C: // ㅈ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x110E: // ㅊ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[3] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x110F: // ㅋ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2];
			if (prev_is_figure())
				Enqueue_char(queue, 0);
			Enqueue_char(queue, data);
			break;
		case 0x1110: // ㅌ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x1111: // ㅍ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			if (prev_is_figure())
				Enqueue_char(queue, 0);
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x1112: // ㅎ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			if (prev_is_figure())
				Enqueue_char(queue, 0);
			data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x1101: // ㄲ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[1];
			Enqueue_char(queue, data);
			break;
		case 0x1104: // ㄸ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[1] + SOL_NUM[2];
			Enqueue_char(queue, data);
			break;
		case 0x1108: // ㅃ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[1] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x110A: // ㅆ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x110D: // ㅉ
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[1] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
			/***************종성*******************/
		case 0x11A8: // ㄱ
			if (prev == 0x1165) { // 억
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[5];
			}
			else if (prev == 0x1169) { // 옥
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[4] + SOL_NUM[5];
			}
			else
				data = SOL_NUM[0];
			Enqueue_char(queue, data);
			break;
		case 0x11AB: // ㄴ
			if (prev == 0x1165) { // 언
				Dequeue_Back_char(queue);
				data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
			}
			else if (prev == 0x1167) { // 연
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[5];
			}
			else if (prev == 0x116E) { // 운
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3];
			}
			else if (prev == 0x1169) { // 온
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
			}
			else if (prev == 0x1173) { // 은
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
			}
			else if (prev == 0x1175) { // 인
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			}
			else
				data = SOL_NUM[2] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x11AE: // ㄷ
			data = SOL_NUM[3] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x11AF: //ㄹ
			if (prev == 0x1165) { // 얼
				Dequeue_Back_char(queue);
				data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			}
			else if (prev == 0x1167) { // 열
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
			}
			else if (prev == 0x116E) { // 울
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[4] + SOL_NUM[5];
			}
			else if (prev == 0x1173) { // 을
				Dequeue_Back_char(queue);
				data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[4] + SOL_NUM[5];
			}
			else
				data = SOL_NUM[2];
			Enqueue_char(queue, data);
			break;
		case 0x11B7: //ㅁ
			data = SOL_NUM[2] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x11B8: // ㅂ
			data = SOL_NUM[0] + SOL_NUM[2];
			Enqueue_char(queue, data);
			break;
		case 0x11BA: //ㅅ
			if (prev == 0x1165) { // 엇
				if (prevv == 0x1101) { // 껏
					Dequeue_Back_char(queue);
					Dequeue_Back_char(queue);
					Dequeue_Back_char(queue);
					data = SOL_NUM[5];
					Enqueue_char(queue, data);
					data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[5];
					Enqueue_char(queue, data);
					data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[4];
				}
				else {
					Dequeue_Back_char(queue);
					data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[5];
					Enqueue_char(queue, data);
					data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[4];
				}
			}
			else
				data = SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x11BC: // ㅇ
			if ((prev == 0x1165) && (prevv == 0x1109 || prevv == 0x110C || prevv == 0x110A || prevv == 0x110D)) {
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
			}
			if (prev == 0x1167) { // 영
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
			}
			else if (prev == 0x1169) { // 옹
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
			}
			else
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x11BD: // ㅈ
			data = SOL_NUM[0] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x11BE: // ㅊ
			data = SOL_NUM[2] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x11BF: // ㅋ
			data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x11C0: // ㅌ
			data = SOL_NUM[2] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x11C1: // ㅍ
			data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x11C2: // ㅎ
			data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
			/***************쌍받침*********************/
		case 0x11A9: // ㄲ
			data = SOL_NUM[0];
			Enqueue_char(queue, data);
			data = SOL_NUM[0];
			Enqueue_char(queue, data);
			break;
		case 0x11BB: // ㅆ
			if (prev == 0x1161 && prevv == 0x1111) {
				data = data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
			/****************겹받침*******************/
		case 0x11AA: // 윿
			data = SOL_NUM[0];
			Enqueue_char(queue, data);
			data = SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x11AC: // 읁
			data = SOL_NUM[2] + SOL_NUM[3];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x11AD: // 읂
			data = SOL_NUM[2] + SOL_NUM[3];
			Enqueue_char(queue, data);
			data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x11B1: // 읆
			data = SOL_NUM[2];
			Enqueue_char(queue, data);
			data = SOL_NUM[2] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x11B0: // 읅
			data = SOL_NUM[2];
			Enqueue_char(queue, data);
			data = SOL_NUM[0];
			Enqueue_char(queue, data);
			break;
		case 0x11B2: // 읇
			data = SOL_NUM[2];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[2];
			Enqueue_char(queue, data);
			break;
		case 0x11B3: // 읈
			data = SOL_NUM[2];
			Enqueue_char(queue, data);
			data = SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x11B4: // 읉
			data = SOL_NUM[2];
			Enqueue_char(queue, data);
			data = SOL_NUM[2] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x11B5: // 읊
			data = SOL_NUM[2];
			Enqueue_char(queue, data);
			data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x11B6: // 읋
			data = SOL_NUM[2];
			Enqueue_char(queue, data);
			data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x11B9: // 읎
			data = SOL_NUM[0] + SOL_NUM[2];
			Enqueue_char(queue, data);
			data = SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
			/*********************모음********************/
		case 0x1161: // ㅏ
			if (prev == 0x1100) { // 가
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[5];
			}
			if (prev == 0x1101) { // 까
				Dequeue_Back_char(queue);
				Dequeue_Back_char(queue);
				data = SOL_NUM[5];
				Enqueue_char(queue, data);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[5];
			}
			else if (prev == 0x1102) { // 나
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1];
			}
			else if (prev == 0x1103) { // 다
				Dequeue_Back_char(queue);
				data = SOL_NUM[1] + SOL_NUM[2];
			}
			else if (prev == 0x1106) { // 마
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[3];
			}
			else if (prev == 0x1107) { // 바
				Dequeue_Back_char(queue);
				data = SOL_NUM[1] + SOL_NUM[3];
			}
			else if (prev == 0x1109) { // 사
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1];
			}
			if (prev == 0x110A) { // 싸
				Dequeue_Back_char(queue);
				Dequeue_Back_char(queue);
				data = SOL_NUM[5];
				Enqueue_char(queue, data);
				data = SOL_NUM[0] + SOL_NUM[1];
			}
			else if (prev == 0x110C) { // 자
				Dequeue_Back_char(queue);
				data = SOL_NUM[1] + SOL_NUM[5];
			}
			else if (prev == 0x110F) { // 카
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2];
			}
			else if (prev == 0x1110) { // 타
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3];
			}
			else if (prev == 0x1111) { // 파
				Dequeue_Back_char(queue);
				data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[3];
			}
			else if (prev == 0x1112) { // 하
				Dequeue_Back_char(queue);
				data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3];
			}
			else
				data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x1163: // ㅑ
			data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x1165: // ㅓ
			data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x1167: // ㅕ
			data = SOL_NUM[0] + SOL_NUM[3] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x1169: // ㅗ
			data = SOL_NUM[0] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x116D: // ㅛ
			data = SOL_NUM[1] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x116E: // ㅜ
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x1172: // ㅠ
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x1173: // ㅡ
			data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x1175: // ㅣ
			data = SOL_NUM[0] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x1162: // ㅐ
			if ((prev == 0x110B) && (prevv == 0x1163 || prevv == 0x116E || prevv == 0x116A || prevv == 0x116F)) {
				data = SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x1164: // ㅒ
			data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x1166: // ㅔ
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x1168: // ㅖ
			if (!(prevv >= 0x11A8 && prevv <= 0x11C2) && prev == 0x110B) {
				data = SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x116A: // ㅘ
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x116B: // ㅙ
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x116C: // ㅚ
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x116F: // ㅝ
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x1170: // ㅞ
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[4];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x1171: // ㅟ
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[4];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x1174: // ㅢ
			data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
			/**********************figure**************************/
		case 0x0030: // 0
			if (!prev_is_figure()) {
				data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x0031: // 1
			if (!prev_is_figure()) {
				data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0];
			Enqueue_char(queue, data);
			break;
		case 0x0032: // 2
			if (!prev_is_figure()) {
				data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x0033: // 3
			if (!prev_is_figure()) {
				data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[1];
			Enqueue_char(queue, data);
			break;
		case 0x0034: // 4
			if (!prev_is_figure()) {
				data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x0035: // 5	
			if (!prev_is_figure()) {
				data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x0036: // 6	
			if (!prev_is_figure()) {
				data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2];
			Enqueue_char(queue, data);
			break;
		case 0x0037: // 7
			if (!prev_is_figure()) {
				data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x0038: // 8	
			if (!prev_is_figure()) {
				data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x0039: // 9
			if (!prev_is_figure()) {
				data = SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1] + SOL_NUM[2];
			Enqueue_char(queue, data);
			break;

			/**********************Latin**************************/
		case 0x0041: // A
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0];
			Enqueue_char(queue, data);
			break;

		case 0x0042: // B
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[2];
			Enqueue_char(queue, data);
			break;

		case 0x0043: // C
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[1];
			Enqueue_char(queue, data);
			break;

		case 0x0044: // D
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;

		case 0x0045: // E
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;

		case 0x0046: // F
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2];
			Enqueue_char(queue, data);
			break;

		case 0x0047: // G
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;

		case 0x0048: // H
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;

		case 0x0049: // I
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[1] + SOL_NUM[2];
			Enqueue_char(queue, data);
			break;

		case 0x004A: // J
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3];
			Enqueue_char(queue, data);
			break;

		case 0x004B: // K
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;

		case 0x004C: // L
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;

		case 0x004D: // M
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;

		case 0x004E: // N
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;

		case 0x004F: // O
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;

		case 0x0050: // P
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;

		case 0x0051: // Q
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;

		case 0x0052: // R
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;

		case 0x0053: // S
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;

		case 0x0054: // T
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;

		case 0x0055: // U
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;

		case 0x0056: // V
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[2] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;

		case 0x0057: // W
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[1] + SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x0058: // X
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x0059: // Y
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[1] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x005A: // Z
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[5];
			Enqueue_char(queue, data);
			data = SOL_NUM[0] + SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x0061: // a
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0];
			Enqueue_char(queue, data);
			break;
		case 0x0062: // b
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[2];
			Enqueue_char(queue, data);
			break;
		case 0x0063: // c
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[1];
			Enqueue_char(queue, data);
			break;
		case 0x0064: // d
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[1]+ SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x0065: // e
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x0066: // f
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[1]+ SOL_NUM[2];
			Enqueue_char(queue, data);
			break;
		case 0x0067: // g
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[1]+ SOL_NUM[2]+ SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x0068: // h
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[2]+ SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x0069: // i
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1]+ SOL_NUM[2];
			Enqueue_char(queue, data);
			break;
		case 0x006A: // j
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1]+ SOL_NUM[2]+ SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x006B: // k
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x006C: // l
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[2]+ SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x006D: // m
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[1]+ SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x006E: // n
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[1]+ SOL_NUM[3]+ SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x006F: // o
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[3]+ SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x0070: // p
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[1]+ SOL_NUM[2]+ SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x0071: // q
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[1]+ SOL_NUM[2]+ SOL_NUM[3]+ SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x0072: // r
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[2]+ SOL_NUM[3]+ SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x0073: // s
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1]+ SOL_NUM[2]+ SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x0074: // t
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1]+ SOL_NUM[2]+ SOL_NUM[3]+ SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x0075: // u
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[4]+ SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x0076: // v
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[2]+ SOL_NUM[4]+ SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x0077: // w
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[1]+ SOL_NUM[2]+ SOL_NUM[3]+ SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x0078: // x
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[1]+ SOL_NUM[4]+ SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x0079: // y
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[1]+ SOL_NUM[3]+ SOL_NUM[4]+ SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x007A: // z
			if (!prev_is_Latin()) {
				data = SOL_NUM[3] + SOL_NUM[4] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[0]+ SOL_NUM[3]+ SOL_NUM[4]+ SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		/***********************특수문자********************************/
		case 0x002E: // .
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x003F: // ?
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[2] + SOL_NUM[4] + SOL_NUM[5];
			Enqueue_char(queue, data);
			break;
		case 0x0021: // !
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[4];
			Enqueue_char(queue, data);
			break;
		case 0x002C: // ,
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = SOL_NUM[3];
			Enqueue_char(queue, data);
			break;
		case 0x0020: // 공백
			if (prev_is_Latin()) {
				data = SOL_NUM[2] + SOL_NUM[3] + SOL_NUM[5];
				Enqueue_char(queue, data);
			}
			data = 0;
			Enqueue_char(queue, data);
			break;
	}
	prevv = prev;
	prev = unicode;
}
	
