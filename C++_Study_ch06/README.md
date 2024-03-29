# C++의 핵심 키워드
# const

## const 함수

const 함수 : 멤버변수에 저장된 값을 변경하지 않겠다는 선언
**const 함수 내에서는 const가 아닌 함수의 호출이 제한된다.*

⇒ const 선언을 한 번 사용하면 이곳 저곳에 많이 추가해야 하지만, 그만큼 코드의 안전성은 높아진다. 

## 상수화

const 키워드로 변수를 상수화 하듯이,  객체도 상수화 할 수 있다. 

객체의 const 선언이 의미하는 바 : *“이 객체의 데이터 변경을 허용하지 않겠다!”*

### 함수 오버로딩의 조건

1. 매개변수의 자료형 ≠
2. 매개변수의 수 ≠
3. const 선언 유무

# friend

> 객체지향의 정보은닉을 무너뜨리는 문법
> 

클래스 간의 관계를 정의하기 위한 키워드로, 아래와 같은 의미로 정리할 수 있다. 

- A 클래스가 B 클래스를 대상으로 friend 선언을 하면, B 클래스는 A 클래스의 private 멤버에 직접 접근이 가능하다.
- 단, A 클래스도 B 클래스의 private 멤버에 직접 접근이 가능하려면, B 클래스가  A 클래스를 대상으로 friend 선언을 해줘야 한다.

*참고로 friend 선언은 클래스 내 private이나 public 둘 중 어디에 있어도 상관없이 동일한 의미를 지닌다. 

*가급적이면 사용하지 않는 것이 좋음 

클래스 간에 뿐만 아니라, 전역함수나 클래스의 멤버함수를 대상으로도 friend 선언이 가능하다. 

# static

전역변수에 선언된 static의 의미 - 선언된 파일 내에서만 참조를 허용한다. 

함수 내에 선언된 static의 의미 - 한 번만 초기화되고, 지역변수와 달리 함수를 빠져나가도 소멸되지 않는다. 

static 멤버 변수 = 클래스 변수

*static 변수는 전역변수와 마찬가지로 따로 명시되지 않으면 기본 초기화 값이 0으로 설정된다.

**static 멤버변수의 특징**

- static 멤버는 private 으로 선언 시, 해당 클래스에서만 접근이 가능하지만 public 으로 선언 시 클래스 또는 객체 이름을 통해 어디서든 접근이 가능해진다.
- `int SoSimple::simObjCnt = 0;`  → static 변수는 생성자에서 초기화하지 않는다 -> 별도로 정의된 static 멤버변수의 초기화 문법
    
    이는 static 멤버변수가 객체 생성 시 동시에 메모리 공간에 할당되는 것이 아닌, 이미 메모리 공간에 할당에 이루어져 있는 상태이기 때문이다.
    
- static 멤버변수로 선언함으로써 다른 객체의 접근을 막는다.
- static 멤버변수는 객체 내에 존재하지 않는다.
- public static 멤버에 접근할 때는 클래스의 이름을 이용해서 접근하는 것이 좋다. for 클래스 멤버 변수와의 구분

**static 멤버함수의 특징**

- 선언된 클래스의 모든 객체가 공유한다.
- public으로 선언되면, 클래스의 이름을 이용해서 호출이 가능하다.
- **객체의 멤버로 존재하는 것이 아니다.**
    
    ⇒ private 으로 선언된 멤버변수에는 접근이 불가능하다. 
    
    ⇒ static 멤버함수 내에서는 static 멤버변수와 static 멤버함수만 호출이 가능하다. 
    

# mutable

> const 함수 내에서의 값의 변경을 예외적으로 허용한다.
> 

*가급적 사용을 자제해야 하는 키워드이다
