#pragma once

#ifdef QTTEST_BUILD
#define QTTEST_LNKG __declspec(dllexport)
#else
#define QTTEST_LNKG __declspec(dllimport)
#endif
