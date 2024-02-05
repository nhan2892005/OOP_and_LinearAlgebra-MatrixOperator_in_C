# Matrix Solution by C++

## Giới thiệu về dự án
Đây là dự án dành cho người mới bắt đầu học tập và nghiên cứu về Khoa học Máy tính

Dự án giúp cho sinh viên tiếp cận với cách quản lý source code, làm việc với file header C, làm quen với thao tác xuất nhập trên file, đưa ra giải pháp và thuật toán xử lý ma trận

Dự án sẽ bao gồm các phép:
  - Kiểm tra các loại ma trận
  - Phép tính ma trận
  - Phương tình ma trận
  - Các phép biến đổi sơ cấp
  - Tìm định thức
  - Hạng ma trận
  - Ma trận nghịch đảo
  - Đưa về ma trận bậc thang
  - Và một số thuật toán khác liên quan tới ma trận

Với các hàm đã được định nghĩa trong source code, người dùng sẽ dễ dàng thao tác với ma trận

- Nhập ma trận: Việc nhập ma trận thực hiện trong file `insert-n-print-data/initMatrix.inp` và được định nghĩa như sau:
  + Dòng đầu tiên: Tên Ma trận
  + Dòng thứ hai: số lượng hàng và cột của ma trận
  + Các dòng tiếp theo: nhập ma trận theo đúng số hàng và cột đã được định nghĩa ở dòng trước
  * Notes: Có thể nhập nhiều ma trận trong cùng 1 file

- Xem ma trận đã nhập: Ma trận bạn đã nhập được lưu trữ tại `insert-n-print-data/printMatrix.out`

- Thực hiện các phép với 1 ma trận: Việc nhập các phép toán thực hiện trong file `check_matrix\question_matrix.inp` được định nghĩa như sau:
  + <Tên ma trận> <Tên phép toán>
  * Notes: Có thể nhập nhiều phép toán trong cùng 1 file
  * Ví dụ:

           Hello isSquare
           World det
    
    * Tôi sẽ cung cấp các hàm sau đây:
      | Phép toán           | Mô tả                                        | Nguyên mẫu                         |
      |---------------------|----------------------------------------------|------------------------------------|
      | `isSquare`          | Kiểm tra ma trận vuông                       | `bool isSquare()`                  |
      | `isDiagonal`        | Kiểm tra ma trận chéo                        | `bool isDiagonal()`                |
      | `isIdentity`        | Kiểm tra ma trận đơn vị                      | `bool isIdentity()`                |
      | `isSymmetric`       | Kiểm tra ma trận đối xứng                    | `bool isSymmetric()`               |
      | `isSkewSymmetric`   | Kiểm tra ma trận chéo phụ                    | `bool isSkewSymmetric()`           |
      | `isUpperTriangular` | Kiểm tra ma trận tam giác trên               | `bool isUpperTriangular()`         |
      | `isLowerTriangular` | Kiểm tra ma trận tam giác dưới               | `bool isLowerTriangular()`         |
      | `isTriangular`      | Kiểm tra ma trận tam giác (tổng quát)        | `bool isTriangular()`              |
      | `isOrthogonal`      | Kiểm tra ma trận trực giao                   | `bool isOrthogonal()`              |
      | `isInvolutory`      | Kiểm tra ma trận A^2=I                       | `bool isInvolutory()`              |
      | `isNilpotent`       | Kiểm tra ma trận luỹ linh                    | `bool isNilpotent()`               |
      | `isIdempotent`      | Kiểm tra ma trận luỹ đẳng                    | `bool isIdempotent()`              |
      | `isInvertible`      | Kiểm tra ma trận khả nghịch                  | `bool isInvertible()`              |
      | `det`               | Tính định thức ma trận vuông                 | `double det()`                     | 
      | `rank`              | Tính hạng ma trận                            | `int rank()`                       |
      | `transpose`         | Ma trận chuyển vị                            | `Matrix transpose()`               |
      | `transformEchelon`  | Chuyển ma trận về dạng bậc thang             | `Matrix transformEchelon`          |
      | `inverse`           | Ma trận nghịch đảo                           | `Matrix inverse()`                 |

- Xem kết quả sau khi chạy ở file `check_matrix\result_matrix.out`

- Để thực hiện tính toán với biểu thức trên ma trận, sau khi biên dịch và chạy chương trình, người dùng nhập biểu thức ở Terminal và quan sát kết quả ở file `result_expression_matrix.out`.

- Việc nhập biểu thức có một số ràng buộc sau đây:
    + Nếu là biểu thức có luỹ thừa, số mũ phải được đặt trong cặp dấu `{}`
          VD:
      
                Hello^{T}+Hello
                A^{-1} * B
      
    + Các biến trong biểu thức phải được định nghĩa trước
          VD: Tôi đã định nghĩa trước 2 ma trận Hello và World

                Hello + World

    + Một số trường hợp khác có thể là lỗi hoặc tính năng, tuy nhiên sẽ không thường xuyên gặp trong quá trình giải ma trận, mong các bạn bỏ qua
 
- Trong file ParserExpression.md, tôi sẽ chia sẻ về cách xử lý các biểu thức đầu vào. Mong các bạn đón xem.
  
## Quá trình tiếp cận dự án
Sau quá trình tiếp cận với môn Đại số tuyến tính và Kỹ thật lập trình ở trường Đại học Bách Khoa Tp.HCM, tôi đã nghĩ tới dự án này như một cách để hiểu rõ hơn về 2 môn học này.

## Hướng đi tiếp theo của dự án

- Dùng các phương pháp xử lý ảnh, ML/DL để đọc ma trận từ ảnh.

- Nếu đã đọc được ma trận từ ảnh, sẽ phát triển đọc các biểu thức ma trận từ ảnh

- Xây dựng mô hình AI giải ma trận qua hình ảnh, text, dữ liệu nhập, ...

Những hướng đi trên chỉ là kế hoạch trong một tương lai xa nào đó của tác giả.

## Tài liệu tham khảo

Giáo trình Đại số tuyến tính - Trường Đại học Bách Khoa-ĐHQG TPHCM - Thầy Đặng Văn Vinh

Đại số tuyến tính - Thầy Nguyễn Hữu Hiệp

[Data Structures and Algorithms in C++ - Adam Drozdek](https://itlectures.ro/wp-content/uploads/2016/04/AdamDrozdek__DataStructures_and_Algorithms_in_C_4Ed.pdf)

[Reverse Polish Notation]([https://mathworld.wolfram.com/ReversePolishNotation.html#:~:text=Reverse%20Polish%20notation%20(RPN)%20is,the%20Polish%20mathematician%20Jan%20Lucasiewicz.])

[Evaluate the Value of an Arithmetic Expression in Reverse Polish Notation](https://www.geeksforgeeks.org/evaluate-the-value-of-an-arithmetic-expression-in-reverse-polish-notation-in-java/)

Nhân
`nhan.nguyen2005phuyen@hcmut.edu.vn`
HCMUT 24/01/2024.
