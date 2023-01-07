#ifndef VECTOR_TPP
#define VECTOR_TPP

template < class T, class Allocator >
ft::vector<T, Allocator >::vector(const Allocator& alloc )
{
  std::cout << "tst\n";
  (void)alloc;
}


#endif
