#include <iostream>

using namespace std;
class Point{
    int x;
    int y;
public:
    Point(int _x,int _y){
        x=_x;
        y=_y;

    }
    Point(){
        x=0;
        y=0;
    }
    void setx_y(int x1,int y1){
        x=x1;
        y=y1;
    }
    int getx()const{
        return x;
    }
    int gety()const{
        return y;
    }
    void print_x_y()const{
        cout<<"("<<x<<","<<y<<")";

    }
};
class PointsArray{
    Point**array;
    int rows;
    int columns;
public:
    PointsArray(int r,int c){
        rows=r;
        columns=c;
        array=new Point*[rows];
        for(int i=0;i<rows;i++){
            array[i]=new Point[columns];
        }
    }
    PointsArray(const PointsArray&copy){
        rows=copy.rows;
        columns=copy.columns;
        array=new Point*[rows];
        for(int i=0;i<rows;i++){
            array[i]=new Point[columns];
            for(int j=0;j<columns;j++){
                array[i][j]=copy.array[i][j];
            }
        }
    }
    int getRows()const{
        return rows;
    }
    int getColumns()const{
        return columns;
    }
    void setpoint(int row,int column,const Point &point){
        array[row][column]=point;
    }
    void swapRows(int r1,int r2){
        Point*temp=array[r1];
        array[r1]=array[r2];
        array[r2]=temp;
    }
    void deleteColumns(int c){
        for(int i=0;i<rows;i++){
            for(int j=c;j<columns-1;j++){
                array[i][j]=array[i][j+1];
            }
        }
        columns--;
    }
    void addColumns(int index,Point*c){
            columns++;
            for (int i = 0; i < rows; i++) {
                for (int j = columns - 1; j > index; j--) {
                    array[i][j] = array[i][j - 1];
                }
                array[i][index] = c[i];
            }


    }
    void print(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                array[i][j].print_x_y();
                if(j<columns-1){
                    cout<<",";
                }
            }
            cout<<endl;


        }



    }
    ~PointsArray() {
        for (int i = 0; i < rows; i++) {
            delete[]array[i];
        }
        delete[]array;
    }
    friend istream& operator>>(istream &is,PointsArray& pointsArray);
    friend ostream& operator<<(ostream &os, const PointsArray & pointsArray);
    PointsArray&operator=(const PointsArray&obj){
                rows=obj.rows;
                columns=obj.columns;
                array=new Point*[rows];
                for(int i=0;i<rows;i++){
                    array[i]=new Point[columns];
                    for(int j=0;j<columns;j++){
                        array[i][j]=obj.array[i][j];
                    }
                 }
    }
    PointsArray operator+(int number)const{
        PointsArray result(rows,columns);
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                result.array[i][j].setx_y(array[i][j].getx()+number,array[i][j].gety()+number);
            }
        }
        return result;
    }
};
istream& operator>>(istream &in,PointsArray& pointsArray){
    for (int i=0;i<pointsArray.getRows();i++){
        for(int j=0;j<pointsArray.getColumns();j++){
            int x,y;
            in>>x>>y;
            pointsArray.array[i][j].setx_y(x,y);
        }
    }
    return in;
}
 ostream& operator<<(ostream &os, const PointsArray & pointsArray){
     for (int i=0;i<pointsArray.getRows();i++) {
         for (int j = 0; j < pointsArray.getColumns(); j++) {
             os << pointsArray.array[i][j].getx() << " " << pointsArray.array[i][j].gety();
             if (j < pointsArray.getColumns() - 1) {
                 os << ", ";
             }

         }
         if (i < pointsArray.getRows() - 1) {
             os << endl;
         }

     }
     return os;


}
bool validateNumber(string &s){
    try{
        stoi(s);
        return true;
    }
    catch (invalid_argument){
        return false;
    }
}

int main() {
    string schoice;
    int choice=0;
    PointsArray p1(0,0);

    while (choice!=12) {
        cout << "1. Initialize PointsArray"<<endl;
        cout << "2. Copy PointsArray"<<endl;
        cout << "3. Number of Rows"<<endl;
        cout << "4. Number of Columns"<<endl;
        cout << "5. Enter PointsArray elements"<<endl;
        cout << "6. PointsArray elements"<<endl;
        cout << "7. Add Integer to PointsArray"<<endl;
        cout << "8. Swap rows"<<endl;
        cout << "9. delete column"<<endl;
        cout << "10. add Column"<<endl;
        cout << "11. Print PointsArray as matrix"<<endl;
        cout << "12. Exit"<<endl;
        cout << " choice: "<<endl;
        cin>>schoice;
        if(validateNumber(schoice)){
            choice = stoi(schoice);
        }
        else{
            continue;
        }
        switch (choice) {
            case 1: {
                int rows,columns;
                cout<<"enter number of rows: ";
                cin>>rows;
                cout<<"enter number of columns: ";
                cin>>columns;
                p1=PointsArray(rows,columns);
                break;
            }
            case 2: {
                PointsArray p2=p1;
                cout<<"copied array: "<<endl;
                p2.print();
                break;
            }
            case 3: {
                cout<<"number of rows equals:"<<p1.getRows()<<endl;
                break;

            }
            case 4: {
                cout<<"number of columns equals"<<p1.getColumns()<<endl;
                break;

            }
            case 5: {
                cout<<"enter points array elements"<<endl;
                cin>>p1;
                break;

            }
            case 6: {
                cout<<"array elements are: "<<p1<<endl;
                break;
            }
            case 7: {
                int addednumber;
                cout<<"enter integer to be added: ";
                cin>>addednumber;
                PointsArray p3=p1+addednumber;
                cout<<"new points array is: "<<p3<<endl;
                break;
            }
            case 8: {
                int r1,r2;
                cout<<"enter rows to be swaped"<<endl;
                cin>>r1>>r2;
                p1.swapRows(r1,r2);
                cout<<"swaped rows are";
                cout<<p1<<endl;
                break;
            }
            case 9: {
                int c;
                cout<<"enter column to be deleted"<<endl;
                cin>>c;
                p1.deleteColumns(c);
                cout<<"array after deleting column"<<endl;
                cout<<p1<<endl;
                break;

            }
            case 10: {
                int col;
                cout<<"enter new column position: "<<endl;
                while (true) {
                    cin >> col;

                    if (col >= 0 && col <= p1.getColumns()) {
                        break;
                    } else {
                        cout << "Invalid: ";
                    }
                }

                Point *addedpoints= new Point[p1.getRows()];
                cout<<"enter new points values: "<<endl;
                for(int i=0;i<p1.getRows();i++){
                    int x,y;
                    cout<<"enter x coordinate: ";
                    cin>>x;
                    cout<<"enter y coordinate: ";
                    cin>>y;
                    addedpoints[i].setx_y(x,y);
                }
                p1.addColumns(col,addedpoints);
                cout<<"array after adding column: "<<p1<<endl;
                break;
            }
            case 11: {
                cout<<"2D point array: ";
                p1.print();
                break;
            }
            case 12: {
                cout << "Exiting the program" << endl;
                break;
                default:
                    cout << "Invalid choice enter a valid choice." << endl;
            }

        }
    }


    return 0;

}
