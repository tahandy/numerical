program main
    use testInterface
    implicit none

    print *,'Calling test1()'
    call test1()

    print *,'Calling test1(1)'
    call test1(1)

    print *,'Calling test3()'
    call test3()

    print *,'Calling test3(1)'
    call test3(1)

end program main
