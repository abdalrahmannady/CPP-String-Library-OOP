# C++ String Library (OOP) 🚀

مكتبة متكاملة للتعامل مع النصوص (Strings) بلغة C++، مصممة بأسلوب البرمجة كائنية التوجه (OOP) لتسهيل العمليات المعقدة في سطر واحد.

## ✨ المميزات (Features)
- **Case Management**: تحويل النصوص لـ UpperCase أو LowerCase.
- **Counting**: حساب عدد الحروف الكبيرة، الصغيرة، المتحركة (Vowels)، أو حرف معين.
- **Trimming**: تنظيف المسافات من اليمين أو اليسار أو الطرفين.
- **Transformation**: عكس الكلمات (Reverse)، واستبدال النصوص (Replace).
- **Split & Join**: تقسيم النصوص لـ Vector أو تجميعها بفاصل معين.

## 🛠 كيف تستخدم المكتبة (How to use)

```cpp
#include "clsString.h"

int main() {
    // (Object-oriented) استخدام الـ
    clsString str("hello world from egypt");
    str.Value = str.UpperFirstLetterOfEachWord();
    std::cout << str.Value; // Output: Hello World From Egypt

    // استخدام الـ Static functions مباشرة
    string s = clsString::ReverseWords("I love C++");
    // Output: C++ love I
}