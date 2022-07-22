# Weight parser

본 파일은 Weight parser를 구현과정을 정리한다.  
수행 환경은 Windows에서 Python, Pytorch, Anaconda를 이용한다.  
구현한 LeNet은 ```~/python/lenet.py```을 이용한다.

Todo list  
- [ ] *pth*를 직접 인코딩/디코딩 할 수 있는 방법찾기
- [ ] Weight 출력에서 ... 값 출력 방법 찾기

진행상황
- PyTorch의 내장 Lenet-5 구조를 이용
- Lenet-5 tutorial code 사용
- Lenet-5을 구조를 이용해 학습, 검증등을 수행해 보지 않음

## PyTorch 설치
[PyTorch](https://pytorch.org) 홈페이지 접근해 실행환경 선택해 command 획득
- **Windows 10 기준**
  - PyTorch 설치 전 [Anaconda](https://www.anaconda.com/)를 먼저 설치
  - Windows의 PowerShell 실행 후 아래 command 입력
    -  CPU 사용: ```conda install pytorch torchvision torchaudio cpuonly -c pytorch``` 
    -  CUDA11.3 사용: ```conda install pytorch torchvision torchaudio cudatoolkit=11.3 -c pytorch```


## PyTorch model file (*.pt*, *.pth*)
- pt, pth, pkl의 차이  
  - 형식에 차이가 있는 것이 아니라 접미사가 다를 뿐이다.

### PyTorch model file 입출력
```python
# model parameter name: net
torch.save(net.state_dict(), "model_weights.pth") # save model
...

net.load_state_dict(torch.load('model_weights.pth')) # load model
model.eval() 
```
### PyTorch model file 결과
- ~/model_state_dict.pt 참고
- *ASCII, binary 혼합으로 인해 직접 수정 불가능*


## Python으로 model 구조 출력
```python
# model parameter name: net
print(net)
```

```python
# print(net) result
Net(
  (conv1): Conv2d(1, 6, kernel_size=(5, 5), stride=(1, 1))
  (conv2): Conv2d(6, 16, kernel_size=(5, 5), stride=(1, 1))
  (fc1): Linear(in_features=400, out_features=120, bias=True)
  (fc2): Linear(in_features=120, out_features=84, bias=True)
  (fc3): Linear(in_features=84, out_features=10, bias=True)
)
```
## Weight 출력
```python
f = open("parameters.txt", 'w')
for name, p in net.named_parameters():
    print(p)
    f.write("%s\n"% p)
```
```python
f2 = open("parameters.txt", 'w')
for param in net.parameters():
  print(param.data)
  f2.write("%s\n"% param)
```
### PyTorch model file 결과
- parameters.txt 참고
```python
# parameters일부 
Parameter containing:
tensor([[[[ 0.1415,  0.1830,  0.0298, -0.1009,  0.0224],
          [ 0.1232, -0.0906, -0.1308, -0.1727,  0.0568],
          [ 0.1791, -0.1557,  0.0643,  0.0855,  0.1149],
          [-0.0900,  0.0737, -0.1763, -0.0122,  0.1887],
          [-0.0500, -0.0096,  0.1887,  0.0614, -0.0317]]],
          ...
Parameter containing:
tensor([[-0.0268,  0.0434, -0.0123,  ...,  0.0008,  0.0209, -0.0477],
        [ 0.0426, -0.0047,  0.0209,  ..., -0.0248,  0.0210, -0.0231],
        [ 0.0042, -0.0217,  0.0378,  ..., -0.0128,  0.0479, -0.0063],
        ...,
        [-0.0228, -0.0336,  0.0066,  ...,  0.0106,  0.0217,  0.0328],
        [-0.0087, -0.0374, -0.0032,  ..., -0.0171,  0.0236, -0.0106],
        [ 0.0315, -0.0077, -0.0110,  ...,  0.0082, -0.0227, -0.0148]],
       requires_grad=True)
...
```
