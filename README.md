# Matrix Solution by C++

## Giới thiệu về dự án
Đây là dự án dành cho người mới bắt đầu học tập và nghiên cứu về Khoa học Máy tính
Dự án giúp cho sinh viên tiếp cận với các quản lý source code, làm việc với file header C, làm quen với thao tác xuất nhập trên file, đưa ra giải pháp và thuật toán xử lý ma trận

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

- Nhập ma trận: Việc nhập ma trận thực hiện trong file "insert-n-print-data/initMatrix.inp" và được định nghĩa như sau:
  + Dòng đầu tiên: Tên Ma trận
  + Dòng thứ hai: số lượng hàng và cột của ma trận
  + Các dòng tiếp theo: nhập ma trận theo đúng số hàng và cột đã được định nghĩa ở dòng trước
  * Notes: Có thể nhập nhiều ma trận trong cùng 1 file
- Xem ma trận đã nhập: Ma trận bạn đã nhập được lưu trữ tại "insert-n-print-data/printMatrix.out"
- Thực hiện các phép kiểm tra ma trận: Việc nhập các phép kiểm tra thực hiện trong file "check_matrix\want_to_check.inp" được định nghĩa như sau:
  + <Tên ma trận> <Loại ma trận cần kiểm tra>
  * Notes: Có thể nhập nhiều phép kiểm tra trong cùng 1 file
  * Ví dụ: Hello isSquare
    * Tôi sẽ cung cấp các hàm sau đây:
      | Hàm                   | Mô tả                                        | Nguyên mẫu                         |
      |-----------------------|----------------------------------------------|------------------------------------|
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

- Các tính năng khác đang trong quá trình hoàn thiện, chân thành xin lỗi.     
## Quá trình tiếp cận dự án
Sau quá trình tiếp cận với môn Đại số tuyến tính và Kỹ thật lập trình ở trường Đại học Bách Khoa Tp.HCM, tôi đã nghĩ tới dự án này như một cách để hiểu rõ hơn về 2 môn học này.

## Kết thúc
Rất mong mọi người sẽ thấy hứng thú và trở thành đồng tác giả của dự án
