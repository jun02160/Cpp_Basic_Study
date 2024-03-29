## 객체 내에 멤버함수가 존재할까?

사실은 질문에 대한 답은 거짓이다.

객체마다 멤버함수가 존재하는 것이 아닌, 하나의 클래스마다 멤버함수가 존재하며 클래스에 대해 생성되는 여러 개의 객체가 하나의 멤버함수를 공유하는 형태라고 해석할 수 있다. 객체가 지니고 있는 멤버변수 대상의 연산을 멤버함수를 호출하여 진행할 수 있는 것이다. 

# 가상함수 테이블

한 개 이상의 가상함수를 포함하는 클래스에 대해서는 컴파일러가 **가상함수 테이블(V-Table)**이라는 것을 만든다. 이 테이블은 실제 호출되어야 할 함수의 위치정보를 담고 있다. 가상함수 테이블은 key와 value로 이루어져 있고, key는 호출하고자 하는 함수를 구분 지어주는 구분자의 역할을 하며 value는 구분자에 해당하는 함수의 주소정보를 알려주는 역할을 한다. 

https://s3.us-west-2.amazonaws.com/secure.notion-static.com/db944336-7ac0-4d59-a3a3-bad98d0d6321/Untitled.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20221228%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20221228T122139Z&X-Amz-Expires=86400&X-Amz-Signature=3ea28189e7d9be0ae27977f49cc713e182d3beb7a6c239f897a43734fb0ae863&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Untitled.png%22&x-id=GetObject

이때, 오버라이딩 된 가상함수의 주소정보는 유도 클래스의 가상함수 테이블에 포함되지 않는다. 이러한 이유 때문에 오버라이딩 된 가상함수를 호출하면 무조건 가장 마지막에 오버라이딩을 한 유도 클래스의 멤버함수가 호출되는 것이다. 

가상함수 테이블은 main 함수가 호출되기 전에 객체의 생성과 상관없이 메모리 공간에 할당되는데, 이는  멤버함수의 호출에 사용되는 일종의 데이터로 남아있을 뿐이다. 함수의 위치를 저장해두고 오버라이딩 된 함수의 정보 존재 유무에 따라 가상함수를 호출하는 원리로 진행된다. 

# 다중상속(Multiple Inheritance)

다중상속이란?  둘 이상의 클래스를 동시에 상속하는 것

다중상속을 하는 클래스에 같은 이름의 멤버가 존재하는 경우에 다중상속으로 인한 모호성이 발생할 수 있다. 이떄는 어느 클래스에 정의된 함수의 호출을 원하는지 정확히 명시하는 방법으로 해결할 수 있다. 

### 가상 상속

기초 클래스를 여러 번 이상 접근하는 경우, 어느 클래스를 통해서 간접 상속한 기초 클래스의 멤버함수를 호출할 것인지 명시해야 한다. 기초 클래스의 멤버를 하나만 가지도록 하기 위한 해결 방법이 바로 가상 상속이다. virtual 키워드를 이용해  `class 유도클래스 : virtual public 기초클래스` 의 형식으로 명시해주면 여러 개의 클래스가 동시에 상속하는 기초 클래스의 멤버를 하나씩만 가질 수 있게 된다.
