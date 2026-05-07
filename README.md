# RandomCrosshair
Скрипт для смены случайных прицелов CS2

Скрипт выставляет рандомные значения для конфига прицела, что бы их применить вам нужно ввести в консоли "exec crosshair" либо забиндить на какие нибудь кнопки, ниже примеры на что можно забиндить, советую не ставить сразу на всё, а оставить только на ЛКМ.
Если вы случайно вставили не тот путь к корневой папке CS2, то .txt файл с этим путем лежит в C:\config\path_to_cs.txt , можете поменять вручную.
Приятной игры!

Для W
alias "+customw" "+forward; exec crosshair"
alias "-customw" "-forward"
bind "w" "+customw"

Для A
alias "+customa" "+left; exec crosshair"
alias "-customa" "-left"
bind "a" "+customa"

Для S
alias "+customs" "+back; exec crosshair"
alias "-customs" "-back"
bind "s" "+customs"

Для D
alias "+customd" "+right; exec crosshair"
alias "-customd" "-right"
bind "d" "+customd"

Для ЛКМ
alias "+customshoot" "+attack; exec crosshair"
alias "-customshoot" "-attack"
bind "mouse1" "+customshoot"


Чтобы убрать
bind "w" "+forward"
bind "a" "+left"
bind "s" "+back"
bind "d" "+right"
bind "mouse1" "+attack"
