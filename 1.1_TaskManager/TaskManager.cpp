#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

const DWORD busyTime = 10;
const DWORD idleTime = busyTime;

void tm1() {
	for (;;) {
		for (int i = 0; i < 9600000; i++)
			;
		Sleep(10);
	}
}

void tm2() {
	while (1) {
		DWORD startTime = GetTickCount();
		while ((GetTickCount() - startTime <= busyTime))
			;
		Sleep(idleTime);
	}
}

int main() {
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

const DWORD busyTime = 10;
const DWORD idleTime = busyTime;

void tm1() {
	for (;;) {
		for (int i = 0; i < 9600000; i++)
			;
		Sleep(10);
	}
}

void tm2() {
	while (1) {
		DWORD startTime = GetTickCount();
		while ((GetTickCount() - startTime <= busyTime))
			;
		Sleep(idleTime);
	}
}

int main() {
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

const DWORD busyTime = 10;
const DWORD idleTime = busyTime;

void tm1() {
	for (;;) {
		for (int i = 0; i < 9600000; i++)
			;
		Sleep(10);
	}
}

void tm2() {
	while (1) {
		DWORD startTime = GetTickCount();
		while ((GetTickCount() - startTime <= busyTime))
			;
		Sleep(idleTime);
	}
}

int main() {
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

const DWORD busyTime = 10;
const DWORD idleTime = busyTime;

void tm1() {
	for (;;) {
		for (int i = 0; i < 9600000; i++)
			;
		Sleep(10);
	}
}

void tm2() {
	while (1) {
		DWORD startTime = GetTickCount();
		while ((GetTickCount() - startTime <= busyTime))
			;
		Sleep(idleTime);
	}
}

int main() {
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

const DWORD busyTime = 10;
const DWORD idleTime = busyTime;

void tm1() {
	for (;;) {
		for (int i = 0; i < 9600000; i++)
			;
		Sleep(10);
	}
}

void tm2() {
	while (1) {
		DWORD startTime = GetTickCount();
		while ((GetTickCount() - startTime <= busyTime))
			;
		Sleep(idleTime);
	}
}

int main() {
	return 0;
}
