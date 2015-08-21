subroutine test1(arg)
    use testInterface, ONLY: test2
    implicit none

    integer, intent(in), optional :: arg

    call test2(arg)

end subroutine test1
