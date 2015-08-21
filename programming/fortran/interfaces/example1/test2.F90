subroutine test2(arg)
    implicit none

    integer, intent(in), optional :: arg


    if(present(arg)) then
        print *, '[test2] arg is present! value = ', arg
    else
        print *, '[test2] arg is missing!'
    endif

end subroutine test2
