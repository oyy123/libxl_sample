#define libxl_sample
#ifdef libxl_sample

#include <iostream>
#include <windows.h>
#include "libxl.h"

using namespace libxl;

int main()
{
	Book* pbook = xlCreateBook();
	pbook->setKey("Halil Kural", "windows-2723210a07c4e90162b26966a8jcdboe");//set cdkey	

	if (pbook->load("excel_file_name.xls")){

		Sheet * sheetread = pbook->getSheet(0);
		sheetread->writeStr(3, 3, "²âÊÔÒ»ÏÂ ÇëÎÊ");
		sheetread->writeNum(4, 3, 1000);
		sheetread->writeNum(5, 3, 2000);

		//save excel
		if (pbook->save("excel_file_name.xls")){
			::ShellExecute(NULL, "open", "excel_file_name.xls", NULL, NULL, SW_SHOW);
		}
		else{
			std::cout << pbook->errorMessage() << std::endl;
		}
		pbook->release();
	}
	system("pause");

	return 0;
}
#endif