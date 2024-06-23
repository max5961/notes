let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/notes/cpp
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +2 cpp-tutorial/notes.txt
badd +1 cpp-tutorial/hello_world.cpp
badd +1 ~/notes/cpp/notes.txt
badd +31 ~/common/dotfiles/nvim/doc/keybinds.txt
argglobal
%argdel
edit cpp-tutorial/hello_world.cpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 40 + 27) / 54)
exe 'vert 1resize ' . ((&columns * 101 + 105) / 210)
exe '2resize ' . ((&lines * 40 + 27) / 54)
exe 'vert 2resize ' . ((&columns * 108 + 105) / 210)
exe '3resize ' . ((&lines * 11 + 27) / 54)
argglobal
balt ~/notes/cpp/notes.txt
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 31 - ((27 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 31
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("~/notes/cpp/notes.txt", ":p")) | buffer ~/notes/cpp/notes.txt | else | edit ~/notes/cpp/notes.txt | endif
if &buftype ==# 'terminal'
  silent file ~/notes/cpp/notes.txt
endif
balt ~/common/dotfiles/nvim/doc/keybinds.txt
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 1591 - ((27 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1591
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("term://~/notes/cpp//20233:/usr/bin/zsh;\#toggleterm\#1", ":p")) | buffer term://~/notes/cpp//20233:/usr/bin/zsh;\#toggleterm\#1 | else | edit term://~/notes/cpp//20233:/usr/bin/zsh;\#toggleterm\#1 | endif
if &buftype ==# 'terminal'
  silent file term://~/notes/cpp//20233:/usr/bin/zsh;\#toggleterm\#1
endif
balt cpp-tutorial/hello_world.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 11 - ((10 * winheight(0) + 5) / 11)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 11
normal! 0
wincmd w
exe '1resize ' . ((&lines * 40 + 27) / 54)
exe 'vert 1resize ' . ((&columns * 101 + 105) / 210)
exe '2resize ' . ((&lines * 40 + 27) / 54)
exe 'vert 2resize ' . ((&columns * 108 + 105) / 210)
exe '3resize ' . ((&lines * 11 + 27) / 54)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
nohlsearch
let g:this_session = v:this_session
let g:this_obsession = v:this_session
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
