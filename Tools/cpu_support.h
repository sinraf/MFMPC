/*
 * cpu_support.h
 *
 */

#ifndef TOOLS_CPU_SUPPORT_H_
#define TOOLS_CPU_SUPPORT_H_

inline bool check_cpu(int func, bool ecx, int feature)
{
    int ax = func, bx, cx = 0, dx;
    __asm__ __volatile__ ("cpuid":
            "+a" (ax), "=b" (bx), "+c" (cx), "=d" (dx));
    return ((ecx ? cx : bx) >> feature) & 1;
}

inline bool cpu_has_adx()
{
#ifdef CHECK_ADX
    return check_cpu(7, false, 19);
#else
    return true;
#endif
}

inline bool cpu_has_bmi2()
{
#ifdef CHECK_BMI2
    return check_cpu(7, false, 8);
#else
    return true;
#endif
}

inline bool cpu_has_avx2()
{
#ifdef CHECK_AVX2
    return check_cpu(7, false, 5);
#else
    return true;
#endif
}

inline bool cpu_has_avx()
{
#ifdef CHECK_AVX
    return check_cpu(1, true, 28);
#else
    return true;
#endif
}

inline bool cpu_has_pclmul()
{
#ifdef CHECK_PCLMUL
    return check_cpu(1, true, 1);
#else
    return true;
#endif
}

inline bool cpu_has_aes()
{
#ifdef CHECK_AES
    return check_cpu(1, true, 25);
#else
    return true;
#endif
}

#endif /* TOOLS_CPU_SUPPORT_H_ */
