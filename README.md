# Space Alone
**Space Alone은 기존 LOB(The Lord of BOF)를 Ubuntu 22.04 환경에 맞춰 조정한 정신적 계승작 입니다.** 

## 소개
**Space Alone**은 기존 **LOB(The Lord of BOF)**의 정신적 계승작으로, Ubuntu 22.04 환경에서 실행되도록 설계된 보안 취약점 학습 및 도전형 문제집입니다.

이 프로젝트는 처음 시스템 해킹을 공부하시는 분들이 **버퍼 오버플로우(BOF), ROP, FSB** 등의 다양한 보안 취약점 공격 기법을 실습할 수 있도록 구성되어 있으며, 단계별로 난이도가 상승하는 챌린지 형식으로 진행됩니다.


## 환경
- Oracle VirtualBox
- Ubuntu 22.04

## 접속방법
### 챌린지
1. `SpaceAlone.ova` 파일을 [다운](https://drive.google.com/file/d/11Bx_1c9ZLMwlAEsJ4ZtP48HuYGbb5m7a/view?usp=sharing)받습니다. 
2. Oracle VirtualBox에서 `파일 > 가상 시스템 가져오기`를 눌러 `SpaceAlone.ova`를 추가합니다.
3. 추가된 가상머신을 실행시켜줍니다.
4. 다음 명령어를 이용해서 접속하면 됩니다.
```bash
ssh chall@localhost -p 6022
#Password: start
```
### 추가 환경 설정
sudo 명령어를 사용가능한 계정은 다음 명령어를 통해서 접속가능합니다. 
```bash
ssh knight@localhost -p 6022
#Password: 1234
#Root Password: 1234
```

## 커스텀 명령어
- `cmd` → 사용 가능한 **커스텀 명령어 목록을 확인**하는 명령어  
- `story` → 현재 진행 중인 **스토리를 출력**하는 명령어  
- `chap` → 현재 **진행 중인 챕터를 확인**하는 명령어  
- `status` → **진행 상황, 비밀번호 등을 출력**하는 명령어  
- `next` → **다음 챕터로 이동**하는 명령어

## 문제
<details>
<summary>챕터별 기법 (스포일러 방지)</summary> 
   
|  챕터   |           기법            |
| :---: | :---------------------: |
| Ch 1  |        Basic BOF        |
| Ch 2  |     Basic Shellcode     |
| Ch 3  |        Stack BOF        |
| Ch 4  |        Basic ROP        |
| Ch 5  |        BOF, ROP         |
| Ch 6  |        Canary, BOF      |
| Ch 7  |   OOB, GOT Overwrite    |
| Ch 8  |           FSB           |
| Ch 9  |       Stack Pivot       |
| Ch 10 | FSB, libc GOT Overwrite |

</details>

## 풀이방법
모든 문제에는 소스코드가 제공되며, 다음 스테이지로 넘어가기 위한 바이너리는 setuid가 걸려있기 때문에 디버깅이 불가능합니다. 바이너리를 복사하여 사용하면 정상적으로 디버깅이 가능합니다.    
쉘을 얻은 이후 `status` 명령어를 이용해 비밀번호를 얻고 `next` 명령어로 다음 스테이지로 넘어가면 됩니다. 

## 기본 규칙
1. 모든 문제는 주어진 계정(chall) 내에서 해결해야 합니다.
2. root 계정으로 직접 문제를 푸는 것은 금지됩니다.
3. 시스템 설정을 변경하거나 환경을 손상시키는 행위는 금지됩니다.
   - 원하는 도구를 설치하여 문제를 풀이 할 수 있습니다.

## 참여 멤버
### 문제 출제
|   **출제자**    | **출제 문제**  |
| :----------: | :--------: |
|  **Arkea**   | Ch 1, Ch 2 |
|   **156**    | Ch 3, Ch 4 |
|  **finder**  |    Ch 5    |
|  **Osori**   | Ch 6, Ch 7 |
| **yosimich** | Ch 8, Ch 9 |
| **circler**  |   Ch 10    |

### 환경 설정
 **Arkea** : VM 환경 설정 및 커스텀 명령어 구현   
 **Osori** : 커널 커스텀 및 추가 기능 구현  



# 레퍼런스
-  **[해커스쿨 The Lord of BOF](https://www.hackerschool.org/HS_Boards/zboard.php?id=HS_Notice&no=1170881885)**  
   - 본 프로젝트는 해커스쿨의 "The Lord of BOF"에서 영감을 받아 제작되었습니다. 원 제작자 mongii 님께 감사의 말씀을 드립니다. 

# 이슈
문제 발생시 본 레포지토리의 이슈탭에 글을 남겨주세요. 

