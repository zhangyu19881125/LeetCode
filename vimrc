" set UTF-8 encoding
set enc=utf-8
set fenc=utf-8
set termencoding=utf-8
set noswapfile

" disable vi compatibility (emulation of old bugs)
set nocompatible
set backspace=indent,eol,start

" use indentation of previous line
set autoindent

" use intelligent indentation for C
set smartindent

" configure tabwidth and insert spaces instead of tabs
set tabstop=4        " tab width is 4 spaces
set shiftwidth=4     " indent also with 4 spaces
set expandtab        " expand tabs to spaces

" wrap lines at 120 chars. 80 is somewaht antiquated with nowadays displays.
set textwidth=120

" turn syntax highlighting on
set t_Co=256
syntax on
colorscheme molokai
set hlsearch

" turn line numbers on
set number
set statusline=%1*%F%m%r%h%w%=\ %2*\ %Y\ %3*%{\"\".(\"\"?&enc:&fenc).((exists(\"+bomb\")\ &&\ &bomb)?\"+\":\"\").\"\"}\ %4*[%l,%v]\ %5*%p%%\ \|\ %6*%LL
hi User1 cterm=none ctermfg=green ctermbg=darkgrey
set laststatus=2

" highlight matching braces
set showmatch
hi Visual cterm=none ctermbg=darkgrey ctermfg=cyan

" intelligent comments
set comments=sl:/*,mb:\ *,elx:\ */

" ignore case only if encounter a UpperCase
set ignorecase
set smartcase

set tags=./tags;tags
set autochdir
let mapleader = ";"
map <c-d> <c-]>
map <c-f> :tag /
map <c-c> :ts<CR>

map <c-m> :BufMRU<CR>
map <c-j> :BufMRUPrev<CR>
map <c-k> :BufMRUNext<CR>
map J <c-j>
map K <c-k>

call plug#begin('~/.vim/plugged')
Plug 'Yggdroot/LeaderF', { 'do': ':LeaderfInstallCExtension' }
Plug 'universal-ctags/ctags'
Plug 'mildred/vim-bufmru'
" Plug 'vim-scripts/global-6.6.8'
call plug#end()

let g:Lf_GtagsAutoGenerate = 0
let $GTAGSLABEL = 'native-pygments'
let $GTAGSCONF = '/home/admin/gtags/share/gtags/gtags.conf'
" noremap <c-d> :<C-U><C-R>=printf("Leaderf gtags -d %s ", expand("<cword>"))<CR><CR>
" noremap <c-r> :Leaderf gtags <CR>

let g:Lf_WorkingDirectoryMode = 'AF'
let g:Lf_RootMarkers = ['.git', '.root']
let g:Lf_DefaultExternalTool='rg'


" Return to last edit position when opening files (You want this!)
autocmd BufReadPost *
     \ if line("'\"") > 0 && line("'\"") <= line("$") |
     \   exe "normal! g`\"" |
     \ endif

let g:Lf_WindowHeight = 0.60
map <Space> <c-f>
map <c-p> :LeaderfFile<CR>
map <c-o> :LeaderfBuffer<CR>
map <c-i> :LeaderfFunction<CR>
map <c-u> :Leaderf rg 
map <c-n> :Leaderf --recall<CR>
map <c-y> :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,<CR>


" auto save session if exist
" set sessionoptions=blank,buffers,curdir
set sessionoptions=buffers

" 如果用vims(vim -S ./session.vim) 命令启动, 那么参数数量为0, 退出时自动保存session
" 如果用vim + 文件名的方式启动, 那么参数数量为1, 那么退出时不会自动保存session
let g:SessionFlag = (argc() == 0)
let g:SessionFile = getcwd() . '/session.vim'
fu! SaveSess()
    if g:SessionFlag
        execute 'mksession! ' . g:SessionFile
    endif
endfunction
autocmd VimLeave * call SaveSess()

fu! RestoreSess()
if filereadable(getcwd() . '/session.vim')
    execute 'so ' . getcwd() . '/session.vim'
endif
endfunction
" autocmd VimEnter * nested call RestoreSess()

