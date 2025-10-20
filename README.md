## 10/11

読み込みのときも必ずmutexをlockするように変更。   
排他制御を構造体ごとに管理するように方針を変更。   
明日からやる。    
`valgrind --tool=helgrind`の全クリを目指す。   


## 10/17
pthread_mutex_tをすべてlockで守るようにしてデータレースが起こらないように修正。   
哲学者がひとりのときにdeadlockを起こすバグを修正。   

`valgrind --tool=drd ./philo 5 800 200 200 4`でデータレースしてるいるかを確かめることができる。
CFLAGSに
`CFLAGS = -g -O1 -fsanitize=address`   を追加。
`setarch $(uname -m) -R ./philo 5 800 200 200 4`