> C++은 프로그램 실행 도중 발생하는 예외적인 상황의 처리를 위한 문법을 제공한다.
> 

*예외란, 문법적인 오류가 아닌 프로그램의 논리에 맞지 않는 상황을 의미한다.

### ❓ if문을 이용한 예외처리

if문을 통해서 예외상황의 발생유무를 확인하고 그에 대한 처리를 진행하는 것이 일반적인 방식이다. BUT 이 방식은 다른 코드와 비슷한 형식을 이루고 있어 단번에 예외임을 알아채기 어렵다. 즉, 예외처리를 위한 코드와 프로그램의 흐름을 구성하는 코드를 쉽게 구분하지 못하는 것이다. 그럼에도 주석으로 예외상황임을 명시하여 if문이 자주 사용되지만 C++의 예외처리 메커니즘을 이용하면 훨씬 효율적이고 좋은 프로그램 설계가 가능해진다. 

## C++의 예외처리 메커니즘

C++은 구조적으로 예외를 처리할 수 있는 메커니즘을 제공함으로써 예외의 처리를 프로그램의 일반적인 흐름에서 독립시키는 것이 가능하고, 이를 통해 코드의 가독성과 유지보수성을 높일 수 있다. 

### try

예외를 발견한다

→ 예외발생에 대한 검사의 범위를 지정할 때 사용 (**예외발생 예상지역**)

try 블록 내에서 예외가 발생하면 C++의 예외처리 메커니즘에 의해 처리될 수 있다. 

### catch

예외를 잡는다

→ try 블록에서 발생한 예외를 처리하는 코드가 담기는 영역
*형태가 리턴형이 없는 함수와 유사

처리할 예외의 종류를 명시하여 예외처리 코드를 블록 내에 삽입한다. 

### throw

예외를 던진다

→ 예외가 발생했음을 알리는 문장

예외상황을 알리는 데이터인 ‘예외 데이터’ 또는 ‘예외 객체’와 함께 사용한다.

<aside>
🤍 *throw*에 의해 던져진 **예외 데이터**는, **예외 데이터**를 감싸는 *try* 블록에 의하여 감지가 되어 이어서 등장하는 *catch* 블록에 의해 처리된다.

</aside>

### 🎲 try블록을 묶는 기준?

예외 발생 시, 예외가 발생한 지점 이후를 실행하는 것이 아니라, catch 블록의 이후가 이어서 실행된다. 즉, try 블록 내에서 예외가 발생하면 예외가 발생한 지점 이후의 나머지 try 영역은 건너뛴다.

try의 범위는 예외가 발생할만한 영역 외에도 일(work)의 단위로 구성하는 것이 좋다. 

### 전달되는 예외의 명시

```java
int ThrowFunc(int num) throw(int, char) {
}
```

함수는 함수명, 매개변수 선언, 반환형 정보와 더불어 전달할 수 있는 예외의 종류(데이터형)와 그 상황에 대한 정보도 담고 있어야 한다. 따라서 함수의 선언 시 위와 같이 어떤 예외가 발생할 수 있는지 종류를 함께 명시해주는 것이 좋다. 

## 예외상황을 표현하는 예외 클래스의 설계

예외 데이터로는 기본 자료형 뿐만 아니라 클래스의 객체가 될 수도 있다. 

### 예외객체란?

예외발생을 알리는 데 사용되는 객체로, 예외객체의 생성을 위해 정의된 클래스를 ‘예외 클래스’라고 한다. 객체를 이용해 예외상황을 알리는 것의 장점은 예외가 발생한 원인에 대한 정보를 보다 자세히 담을 수 있다는 점이다.

예외 클래스에는 해당 예외상황을 잘 표현할 수 있도록 너무 복잡하지 않게 정의하는 것이 좋고, 예외의 표현을 위한 최소한의 기능만을 담는 것이 좋다. 

*상속을 이용하면 예외의 처리를 단순화시킬 수 있다!

### 모든 예외를 처리하는 catch 블록

```java
try {
		...
} **catch(...) {**
		...
}
```

catch의 매개변수 선언에 …을 넘겨주면 전달되는 모든 예외를 다 받아주겠다는 선언이다. 하지만 이는 가급적 사용을 자제하는 것이 좋다. 발생한 예외에 관련해서 그 어떠한 정보도 전달받을 수 없으며, 전달된 예외의 종류도 구분이 불가능하기 떄문이다.