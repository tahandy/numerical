module testInterface
    implicit none

    interface
        subroutine test1(arg)
            implicit none
            integer, intent(in), optional :: arg
        end subroutine test1
    end interface

    interface
        subroutine test2(arg)
            implicit none
            integer, intent(in), optional :: arg
        end subroutine test2
    end interface

    interface
        subroutine test3(arg)
            implicit none
            integer, intent(in), optional :: arg
        end subroutine test3
    end interface

end module testInterface
