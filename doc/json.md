# JSON (JavaScript Object Notation)
- JSON 표현식은 사람과 기계 모두 이해하기 쉬우며 용량이 작아서, 최근에는 JSON이 XML을 대체해서 데이터 전송 등에 많이 사용한다.
- JSON은 데이터 포맷일 뿐이며 어떠한 통신 방법도, 프로그래밍 문법도 아닌 단순히 데이터를 표시하는 표현 방법일 뿐이다.

# JSON Grammar
## 자료형
- 수 (number)
- 문자열 (string)
- 참/거짓 (boolean)
- 배열 (Array)
  - 순서가 있는 리스트, 대괄호 사용
- 객체 (Object)
  - 순서가 없는 리스트, 이름/값 쌍으로 이뤄진 데이터
- null

## Array
- Array의 요소는 기본 자료형 이거나 배열 객체 
- 각 요소는 쉼표로 구성됨
- 각 요소가 가지는 순서에는 의미가 있다.
```json
[
    10, // number
    {"v": 20}, // Object
    [30, "마흔"] // array
]

```

## Object
JSON에서 객체란 이름(name)과 값(value)으로 구성된 프로퍼티(property)의 정렬되지 않은 집합
```json
{
    "name": "식빵",
    "family": "웰시코기",
    "age": 1,
    "weight": 2.14
}
```




# Reference
- https://velog.io/@surim014/JSON%EC%9D%B4%EB%9E%80-%EB%AC%B4%EC%97%87%EC%9D%B8%EA%B0%80
- https://ko.wikipedia.org/wiki/JSON