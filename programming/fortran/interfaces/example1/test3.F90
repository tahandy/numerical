subroutine test3(arg)
    use testInterface, ONLY: test2
    implicit none

    integer, intent(in), optional :: arg

    call test2(arg=arg)

end subroutine test3
