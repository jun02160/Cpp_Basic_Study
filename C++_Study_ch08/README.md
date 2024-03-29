## 객체 포인터 변수란?

객체 주소값을 저장하는 포인터 변수

- 해당 클래스의 객체
- 클래스를 상속하는 유도 클래스의 객체

포인터는 위 두 가지를 모두 가리킬 수 있다. 

즉, C++에서 AAA형 포인터 변수는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다. ⇒ 객체의 주소값을 저장할 수 있다는 의미와 동일

IS-A 관계에 의해, 유도 클래스는 기본 클래스의 일종으로 간주하고 이는 간접 상속의 관계 속에서도 유지가 된다.

```
AAA ← BBB ← CCC

- BBB는 AAA이다.
- BBB는 AAA의 일종이다.

- CCC는 BBB이다.
- CCC는 BBB의 일종이다.

- CCC는 AAA이다.
- CCC는 AAA의 일종이다. 
```

위 관계에서 AAA형 포인터 변수는 AAA 객체, BBB 객체, CCC 객체를 모두 가리킬 수 있고, BBB형 포인터 변수는 BBB 객체, CCC 객체를 모두 가리킬 수 있다. 

## 함수 오버라이딩

함수가 오버라이딩 되면, 오버라이딩 된 기초 클래스의 함수는 오버라이딩을 한 유도 클래스의 함수에 가려진다. 

**함수 오버라이딩(overriding) VS 함수 오버로딩(overloading)**

기초 클래스와 동일한 이름의 함수를 유도 클래스에서 정의한다고 해서 무조건 함수 오버라이딩이 되는 것은 아니다. **매개변수의 자료형 및 개수**가 다르면 이는 함수 오버로딩이 되어 전달되는 인자에 따라서 호출되는 함수가 결정된다. 즉, 함수 오버로딩은 상속의 관계에서도 구성될 수 있다. 

# 가상함수(Virtual Function)

C++ 컴파일러는 포인터 연산의 가능성 여부를 판단할 때, **포인터의 자료형**을 기준으로 판단한다. (실제 가리키는 객체의 자료형은 무관)

즉, 객체형 포인터가 유도 클래스에 접근이 가능한 것은 사실이지만 이를 유도 클래스 객체 포인터에 대입했을 때 컴파일 에러가 발생한다. 하지만 반대로 유도 클래스형 포인터에 기초 클래스형 포인터를 대입하는 것은 가능하다. 컴파일 오류는 발생하지 않고 그냥 넘어가지만 객체를 참조하는 포인터의 형에 따라서 호출할 수 있는 함수가 제한된다. 

**결론적으로, 포인터 형에 해당하는 클래스에 정의된 멤버에만 접근이 가능한 것이다.**

함수를 오버라이딩 했다는 것은 해당 객체에서 호출되어야 하는 함수를 바꾼다는 의미이다. ⇒ 변수의 자료형에 따라 호출되는 함수의 종류가 달라지는 것에 따라 복잡해지는 논리 과정을 해결하기 위해 virtual 키워드로 가상함수 선언이 이루어지도록 할 수 있다. 

**가상함수로 함수를 선언하면 포인터 변수가 실제 가리키는 객체를 참조하여 호출의 대상을 결정한다.** 기존의 경우라면 포인터의 자료형을 기반으로 호출대상이 결정되지만 virtual 키워드 사용 시 예외적으로 처리할 수 있는 것이다. 

## 순수 가상함수

클래스 중에서는 객체 생성을 목적으로 정의되지 않고, 기초 클래스로서의 의미만 가지는 경우가 존재한다. 이를 순수 가상함수로 선언하면 객체의 생성을 문법적으로 막을 수 있다. 

⇒ 순수 가상함수란? 함수의 몸체가 정의되지 않은 함수

하나 이상의 멤버함수를 순수 가상함수로 선언한 클래스 = **추상 클래스(abstract class) =** 객체 생성이 불가능한 클래스

## 가상 소멸자와 참조자

소멸자에 virtual 키워드를 사용하지 않으면 기초 클래스의 소멸자만 호출되는 **메모리 누수** 현상이 발생한다. 객체의 소멸과정에는 delete 연산자에 사용된 포인터 변수의 자료형에 상관없이 모든 소멸자가 호출되어야 하는데, 이를 위해서는 virtual 선언을 소멸자에 붙여주면 된다.

*기초 클래스의 소멸자만 virtual로 선언해도 이를 상속하는 모든 유도 클래스의 소멸자가 ‘가상 소멸자’로 선언된다. (virtual 선언 없이도 적용!)

가상 소멸자가 호출되면, 상속의 계층구조 상 맨 아래에 존재하는 유도 클래스의 소멸자가 대신 호출되면서 기초 클래스의 소멸자가 순차적으로 호출된다. Third → Second → First 와 같이 아래에서부터 역순으로 소멸자가 호출된다. 

### 참조자의 참조 가능성

<aside>
💡 **AAA형 참조자는 AAA 객체 또는 AAA를 직접/간접적으로 상속하는 모든 객체를 참조할 수 있다.**

</aside>

**AAA형 포인터 변수는 AAA 객체 또는 AAA를 직접/간접적으로 상속하는 모든 객체를 가리킬 수 있다. (객체의 주소값을 저장할 수 있다.)**라는 특성이 포인터에 적용되는데, 이는 참조자에서도 마찬가지이다. 

# 다형성(Polymorphism)

다형성은 “모습은 같은데 형태는 다르다”, 즉 “문장은 같은데 결과는 다르다”는 의미를 지니고 있다. 위와 같은 개념을 통틀어서 다형성을 설명할 수 있는데, 같은 함수명으로 호출하더라도 각각 어떤 클래스의 멤버인지를 판별하는 기준이 달라지는 경우와 객체 포인터 변수가 참조하는 객체의 자료형이 상황에 따라 달라지는 경우 모두 다형성이 적용된 것이다.
