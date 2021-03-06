# simple RESTAPI for mobile APP testing

# API 
```
API 목록
/api/user/signup POST 회원가입
/api/user/login POST 로그인

/api/board GET 글 리스트
/api/board POST 글 등록
/api/board/{number} GET 게시글 상세보기

/api/qr POST 큐알 전송 및
```
### /api/user/signup POST
> 회원가입
* 입력값
    - email
    - password
    - nickname
* 리턴값
    - true or false

### /api/user/login POST
> 로그인
* 입력값
    - email
    - password
* 리턴값
    - true or false (Authorization : BEARER TokenString...)

### /api/board GET
> 글 목록(리스트)
* 입력값
* 리턴값
    - List{
        id
        title
        content
    }

### /api/board POST
> 글 등록
* 입력값
    - #Autorization 
    - title
    - content
* 리턴값
    - true of false

### /api/board/{number} GET
> 글 상세보기
* 입력값
* 리턴값
    - title
    - content

### /api/qr POST
> 큐알 전송 및 테스트
* 입력값
    - #Authorization
    - qr
* 리턴값
    - qr with trash value






# 실행 
* 필요사항
    - Openjdk8
    - Maven 
    - Docker
    - Docker-compose
    - WSL2(windows 10 환경일때)
* 실행 순서
```shell
mvn package -f .\ -Dmaven.test.skip=true
docker-compose -f docker-compose-dev.yml up -d 
docker-compose -f docker-compose-production.yml up -d

# 이것을 기반으로 스크립트파일 만들어서 통합해도됨
```




# Manual Maven Build & Docker
* Maven Build
    - mvn clean -f .\
    - mvn package -f .\
    - mvn package -f .\ -Dmaven.test.skip=true
* Dockfile
    - openjdk8 tomcat9 환경
    - docker build --tag spring-template:1.0 .
* 컨테이너 올리기
    - docker run --rm -p 80:8080 spring-template:1.0
* 도커컴포즈 올리기
    - 이름 docker-compose.yml일때 docker-compose up -d
    - 사용자정의 이름은 docker-compose -f something.yml up -d
    - rebuild 원할시 --build 옵션 추가 




